#include "chessBoard.h"

ChessBoard& ChessBoard::operator=(const ChessBoard& b) {
  this->boardCell = b.boardCell;
  return *this;
}