#include "configurationParser.h"

ConfigurationParser* ConfigurationParser::INSTANCE = nullptr;

ConfigurationParser::ConfigurationParser() :
    DEFAULT_CONFIGURATION_PATH(":/config/defaultChessConfig"),
    TERRAIN_RESOURCES(ConfigurationParser::readTerrainMap()),
    PIECE_RESOURCES(ConfigurationParser::readPieceMap()),
    defaultConfig(ConfigurationParser::readDefaultConfig()) {}

ChessBoard ConfigurationParser::constructChessBoard(const QString& filePath) {
    YAML::Node config;
    try {
        config = readConfig(filePath)["chess_configuration"];
    } catch (const std::exception& e) {
        config = defaultConfig["chess_configuration"];
    }

    assertBoardSize(config);

    ChessBoard ret;
    for (int i = 0; i < config.size(); i++) {
        const auto& row = config[i];
        for (int j = 0; j < row.size(); j++) {
            const auto& col = row[j];
            auto team = CHESS_TEAM::UNDEFINED;
            auto type = CHESS_TYPE::UNDEFINED;
            if (col["team"] && col["type"]) {
                team = magic_enum::enum_cast<CHESS_TEAM>(col["team"].as<std::string>()).value();
                type = magic_enum::enum_cast<CHESS_TYPE>(col["type"].as<std::string>()).value();
            }
            auto terrain = magic_enum::enum_cast<CHESS_TERRAIN>(col["terrain"].as<std::string>()).value();
            ret.addCell(ChessPosition(i, j), terrain, ChessPiece(type, team));
        }
    }
    return ret;
}

ChessBoard ConfigurationParser::constructChessBoard() {
    return constructChessBoard(DEFAULT_CONFIGURATION_PATH);
}

void ConfigurationParser::assertBoardSize(const YAML::Node& config) {
    assert(config.size() == ChessBoardLayout::BOARD_HEIGHT);
    for (auto const& row : config) {
        assert(row.size() == ChessBoardLayout::BOARD_WIDTH);
    }
}

YAML::Node ConfigurationParser::readConfig(const QString& dir) {
    if (!QFile::exists(dir)) {
        throw std::runtime_error("Cannot read config");
    }
    QFile configFile(dir);
    configFile.open(QIODevice::ReadOnly);
    QTextStream in(&configFile);
    QString content = in.readAll();
    return YAML::Load(content.toStdString());
}

std::map<CHESS_TEAM, std::map<CHESS_TYPE, QString>> ConfigurationParser::readPieceMap() {
    YAML::Node configRed = ConfigurationParser::defaultConfig["resources"]["pieces"]["red"];
    YAML::Node configBlue = ConfigurationParser::defaultConfig["resources"]["pieces"]["blue"];
    std::map<CHESS_TEAM, std::map<CHESS_TYPE, QString>> map = {
        {CHESS_TEAM::RED, {}},
        {CHESS_TEAM::BLUE, {}},
    };
    for (auto item: configRed) {
        auto type = magic_enum::enum_cast<CHESS_TYPE>(item["type"].as<std::string>()).value();
        auto dir = QString::fromStdString(item["dir"].as<std::string>());
        map.at(CHESS_TEAM::RED).insert({type, dir});
    }
    for (auto item: configBlue) {
        auto type = magic_enum::enum_cast<CHESS_TYPE>(item["type"].as<std::string>()).value();
        auto dir = QString::fromStdString(item["dir"].as<std::string>());
        map.at(CHESS_TEAM::BLUE).insert({type, dir});
    }
    return map;
}

std::map<CHESS_TERRAIN, QString> ConfigurationParser::readTerrainMap() {
    YAML::Node config = defaultConfig["resources"]["terrains"];
    auto map = std::map<CHESS_TERRAIN, QString>();
    for (auto item: config) {
        auto terrain = magic_enum::enum_cast<CHESS_TERRAIN>(item["terrain"].as<std::string>()).value();
        auto dir = QString::fromStdString(item["dir"].as<std::string>());
        map.insert({terrain, dir});
    }
    return map;
}

YAML::Node ConfigurationParser::readDefaultConfig() {
    // Why include this: https://doc.qt.io/qt-5/resources.html#using-resources-in-a-library
    // Since at this stage the qt resource had not been initialized, so it had to be manually initialized
    Q_INIT_RESOURCE(resourceMap);
    return ConfigurationParser::readConfig(DEFAULT_CONFIGURATION_PATH);
}

QString ConfigurationParser::terrainResource(CHESS_TERRAIN terrain) {
    auto ret = TERRAIN_RESOURCES.find(terrain);
    if (ret == TERRAIN_RESOURCES.end()) {
        return {};
    }
    return ret->second;
}

QString ConfigurationParser::pieceResource(CHESS_TEAM team, CHESS_TYPE type) {
    auto ret = PIECE_RESOURCES.find(team);
    if (ret == PIECE_RESOURCES.end()) {
        return {};
    }
    auto ret2 = ret->second.find(type);
    if (ret2 == ret->second.end()) {
        return {};
    }
    return ret2->second;
}

ConfigurationParser& ConfigurationParser::getInstance() {
    if (!ConfigurationParser::INSTANCE) {
        ConfigurationParser::INSTANCE = new ConfigurationParser();
    }
    return *ConfigurationParser::INSTANCE;
}

