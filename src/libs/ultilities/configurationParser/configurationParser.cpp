#include "configurationParser.h"

// Forward declaration
std::map<CHESS_TERRAIN, QDir> readTerrainMap();
std::map<CHESS_TEAM, std::map<CHESS_TYPE, QDir>> readPieceMap();
YAML::Node readDefaultConfig();

// Static initialization
const QDir ConfigurationParser::DEFAULT_CONFIGURATION_PATH(":/config/defaultChessConfig");
const YAML::Node ConfigurationParser::defaultConfig = readDefaultConfig();
std::map<CHESS_TERRAIN, QDir> ConfigurationParser::TERRAIN_RESOURCES = readTerrainMap();
std::map<CHESS_TEAM, std::map<CHESS_TYPE, QDir>> ConfigurationParser::PIECE_RESOURCES = readPieceMap();

ChessBoard ConfigurationParser::constructChessBoard(const QDir& filePath) {
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

YAML::Node ConfigurationParser::readConfig(const QDir& dir) {
    if (!QFile::exists(dir.absolutePath())) {
        throw std::exception("Cannot read config");
    }
    QFile configFile(dir.path());
    configFile.open(QIODevice::ReadOnly);
    QTextStream in(&configFile);
    QString content = in.readAll();
    return YAML::Load(content.toStdString());
}

std::map<CHESS_TEAM, std::map<CHESS_TYPE, QDir>> readPieceMap() {
    YAML::Node configRed = ConfigurationParser::defaultConfig["resources"]["pieces"]["red"];
    YAML::Node configBlue = ConfigurationParser::defaultConfig["resources"]["pieces"]["blue"];
    std::map<CHESS_TEAM, std::map<CHESS_TYPE, QDir>> map = {
        {CHESS_TEAM::RED, std::map<CHESS_TYPE, QDir>()},
        {CHESS_TEAM::BLUE, std::map<CHESS_TYPE, QDir>()},
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

std::map<CHESS_TERRAIN, QDir> readTerrainMap() {
    YAML::Node config = ConfigurationParser::defaultConfig["resources"]["terrains"];
    auto map = std::map<CHESS_TERRAIN, QDir>();
    for (auto item: config) {
        auto terrain = magic_enum::enum_cast<CHESS_TERRAIN>(item["terrain"].as<std::string>()).value();
        auto dir = QString::fromStdString(item["dir"].as<std::string>());
        map.insert({terrain, dir});
    }
    return map;
}

YAML::Node readDefaultConfig() {
    // Why include this: https://doc.qt.io/qt-5/resources.html#using-resources-in-a-library
    // Since at this stage the qt resource had not been initialized, so it had to be manually initialized
    Q_INIT_RESOURCE(resourceMap);
    return ConfigurationParser::readConfig(ConfigurationParser::DEFAULT_CONFIGURATION_PATH);
}


