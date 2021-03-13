#ifndef __CONFIGURATION_PARSER_H
#define __CONFIGURATION_PARSER_H
#include <chessElement/chessBoard/chessBoard.h>

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QStringLiteral>

class ConfigurationParser {
 public:
  ConfigurationParser();
  ~ConfigurationParser();
  ChessBoard constructChessBoard(QDir filePath);
  ChessBoard constructDefaultChessBoard();
  QDir configurationPath =
      QDir(ConfigurationParser::DEFAULT_CONFIGURATION_PATH);

 private:
  static const QString CHESS_DIMENSION;
  static const QString DEFAULT_CONFIGURATION_PATH;
};

extern ConfigurationParser configParser;
#endif  // __CONFIGURATION_PARSER_H