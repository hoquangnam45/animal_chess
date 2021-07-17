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
  YAML::Node config = YAML::Load(content.toStdString())["chess_configuration"];
  assert(config.size() == ChessBoard::BOARD_HEIGHT);
  ChessBoard ret;
  for (auto const& row : config) {
    assert(row.size() == ChessBoard::BOARD_WIDTH);
  }
  std::vector<ChessCell> chessCellVec;
  for (int i = 0; i < config.size(); i++) {
    auto const& row = config[i];
    for (int j = 0; j < row.size(); j++) {
      auto const& col = row[j];
      ChessPiece* chessPiece = nullptr;
      if (col.size() == 2) {
        std::string team = col.operator[]("team").as<std::string>();
        std::string type = col.operator[]("type").as<std::string>();
        chessPiece = new ChessPiece(CHESS_TYPE_DICTIONARY.at(type), CHESS_TEAM_DICTIONARY.at(team));
      }
      ChessCell chessCell(ChessPosition(i, j));
      ret.addCell(chessCell, chessPiece);
    }
  }
  return ret;
}

ChessBoard ConfigurationParser::constructChessBoard() {
  return constructDefaultChessBoard();
}

ChessBoard ConfigurationParser::constructDefaultChessBoard() {
  return ChessBoard();
}
