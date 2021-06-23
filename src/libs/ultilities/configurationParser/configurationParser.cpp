#include "configurationParser.h"

const QString ConfigurationParser::DEFAULT_CONFIGURATION_PATH(
    QString(":/config/defaultChessConfig"));

const QString ConfigurationParser::CHESS_DIMENSION("chess_dimension");

ChessBoard ConfigurationParser::constructChessBoard(QDir& filePath) {
  if (!QFile::exists(filePath.absolutePath())) {
    return constructDefaultChessBoard();
  }
  QFile configFile(filePath.path());
  configFile.open(QIODevice::ReadOnly);
  QTextStream in(&configFile);
  QString content = in.readAll();
  YAML::Node config = YAML::Load(content.toStdString());
  qDebug() << config["chess_configuration"].size();
  assert(config["chess_configuration"].size() == ChessBoard::BOARD_HEIGHT);
  ChessBoard ret;
  for (auto const& row : config["chess_configuration"]) {
    assert(row.size() == ChessBoard::BOARD_WIDTH);
  }
  return ChessBoard();
}

ChessBoard ConfigurationParser::constructChessBoard() {
  return constructDefaultChessBoard();
}

ChessBoard ConfigurationParser::constructDefaultChessBoard() {
  return ChessBoard();
}
