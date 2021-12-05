#pragma once
#include <chessElement/chessBoard/chessBoard.h>
#include <chessElement/chessCell/chessCell.h>
#include <enums/chessTypeEnum/chessTypeEnum.h>
#include <yaml-cpp/yaml.h>
#include <magic_enum.hpp>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QStringLiteral>
#include <QTextStream>
#include <iostream>
#include <string>
#include <vector>
#include <layout/chessBoardLayout.h>

class ConfigurationParser {
    public:
        static ConfigurationParser& getInstance();
        ChessBoard constructChessBoard(const QString& filePath);
        ChessBoard constructChessBoard();
        QString terrainResource(CHESS_TERRAIN terrain);
        QString pieceResource(CHESS_TEAM team, CHESS_TYPE type);
    private:
        ConfigurationParser();
        static ConfigurationParser* INSTANCE;
        static void assertBoardSize(const YAML::Node& config);
        static YAML::Node readConfig(const QString& dir) noexcept(false);
        const QString DEFAULT_CONFIGURATION_PATH;
        const YAML::Node defaultConfig;
        std::map<CHESS_TERRAIN, QString> TERRAIN_RESOURCES;
        std::map<CHESS_TEAM, std::map<CHESS_TYPE, QString>> PIECE_RESOURCES;
        std::map<CHESS_TERRAIN, QString> readTerrainMap();
        std::map<CHESS_TEAM, std::map<CHESS_TYPE, QString>> readPieceMap();
        YAML::Node readDefaultConfig();
};
