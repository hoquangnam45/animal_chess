#include "chessBoard.h"

ChessBoard::ChessBoard() {
  this->boardArray.fill(ChessCell(CHESS_TERRAIN::UNDEFINED));
  new ChessPiece(CHESS_PIECE::UNDEFINED, CHESS_TEAM::UNDEFINED);
};

ChessBoard& ChessBoard::operator=(const ChessBoard& b) { return *this; }