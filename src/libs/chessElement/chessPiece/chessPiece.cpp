#include "chessPiece.h"

ChessPiece::ChessPiece(const CHESS_PIECE& chessPiece,
                       const CHESS_TEAM& chessTeam) {
  this->chessPiece = chessPiece;
  this->chessTeam = chessTeam;
}