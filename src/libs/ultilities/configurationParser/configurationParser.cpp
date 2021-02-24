#include "configurationParser.h"

ChessBoard* ConfigurationParser::constructChessBoard(QDir* filePath) {
  if (QFile::exists(filePath->absolutePath())) {
    this->configurationPath = *filePath;
  }
  // auto map = c4::parse(c4::to_csubstr(filePath));
  return nullptr;
}