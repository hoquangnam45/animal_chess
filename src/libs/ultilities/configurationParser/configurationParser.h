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
        static ChessBoard constructChessBoard(const QDir& filePath);
        static ChessBoard constructChessBoard();
        static std::map<CHESS_TERRAIN, QDir> TERRAIN_RESOURCES;
        static std::map<CHESS_TEAM, std::map<CHESS_TYPE, QDir>> PIECE_RESOURCES;
    private:
        static void assertBoardSize(const YAML::Node& config);
        static YAML::Node readConfig(const QDir& dir) noexcept(false);
        static const QDir DEFAULT_CONFIGURATION_PATH;
        static const YAML::Node defaultConfig;
        friend std::map<CHESS_TERRAIN, QDir> readTerrainMap();
        friend std::map<CHESS_TEAM, std::map<CHESS_TYPE, QDir>> readPieceMap();
        friend YAML::Node readDefaultConfig();
};
