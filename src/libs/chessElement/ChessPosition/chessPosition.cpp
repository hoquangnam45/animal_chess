#include "chessPosition.h"
ChessPosition::ChessPosition(int row, int col) {
  this->row = row;
  this->col = col;
};

ChessPosition::ChessPosition() : ChessPosition(-1, -1){};
ChessPosition::~ChessPosition() {}
