#ifndef __CONFIGURATION_PARSER_H
#define __CONFIGURATION_PARSER_H
#include <chessElement/chessBoard/chessBoard.h>

#include <QDebug>
#include <QDir>
#include <QFile>
#include <c4/format.hpp>
#include <ryml.hpp>
#include <ryml_std.hpp>

class ConfigurationParser {
 public:
  ConfigurationParser();
  ~ConfigurationParser();
  ChessBoard* constructChessBoard(QDir* filePath = nullptr);
  ChessBoard* constructDefaultChessBoard();
  QDir configurationPath = defaultConfigurationPath;

 private:
  const std::string CHESS_DIMENSION = "chess_dimension";
  const QDir defaultConfigurationPath = ":/config/defaultChessConfig";
};

static ConfigurationParser configParser;
#endif  // __CONFIGURATION_PARSER_H