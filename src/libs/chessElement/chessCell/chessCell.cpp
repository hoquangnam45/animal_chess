#include "chessCell.h"

ChessCell::ChessCell(const CHESS_TERRAIN& chessTerrain,
                     ChessPiece* chessPiece) {
  this->chessTerrain = chessTerrain;
  this->standingPiece = chessPiece;
}

ChessCell::~ChessCell() {
  if (this->standingPiece) {
    delete this->standingPiece;
    this->standingPiece = nullptr;
  }
  return;
}
