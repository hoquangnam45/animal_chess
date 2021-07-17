#ifndef __CONFIGURATION_PARSER_H
#define __CONFIGURATION_PARSER_H
#include <chessElement/chessBoard/chessBoard.h>
#include <chessElement/chessCell/chessCell.h>
#include <enums/chessTypeEnum/chessTypeEnum.h>
#include <yaml-cpp/yaml.h>

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QStringLiteral>
#include <QTextStream>
#include <iostream>
#include <string>
#include <vector>

class ConfigurationParser {
 public:
  static ChessBoard constructChessBoard(QDir& filePath);
  static ChessBoard constructChessBoard();

 private:
  static ChessBoard constructDefaultChessBoard();
  static const QString CHESS_DIMENSION;
  static const QString DEFAULT_CONFIGURATION_PATH;
};
#endif  // __CONFIGURATION_PARSER_H