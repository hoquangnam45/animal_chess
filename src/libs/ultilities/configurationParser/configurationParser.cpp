#include "configurationParser.h"

ConfigurationParser configParser = ConfigurationParser();

const QString ConfigurationParser::DEFAULT_CONFIGURATION_PATH(
    QString(":/config/defaultChessConfig"));

const QString ConfigurationParser::CHESS_DIMENSION("chess_dimension");
ChessBoard ConfigurationParser::constructChessBoard(QDir filePath) {
  if (QFile::exists(filePath.absolutePath())) {
    this->configurationPath = filePath;
  }
  // auto map = c4::parse(c4::to_csubstr(filePath));
  return ChessBoard();
}
ConfigurationParser::ConfigurationParser() {}
ConfigurationParser::~ConfigurationParser() {}
ChessBoard ConfigurationParser::constructDefaultChessBoard() {
  return ChessBoard();
}
