#include "chessCell.h"

ChessCell::ChessCell(const ChessPosition& chessPosition) {
  this->chessPosition = chessPosition;
}

ChessCell::ChessCell() {
  return;
}

ChessCell::~ChessCell() {
  if (this->standingPiece) {
    delete this->standingPiece;
    this->standingPiece = nullptr;
  }
  return;
}
