#include "chessPiece.h"

ChessPiece::ChessPiece(
  const CHESS_TYPE& chessType,
  const CHESS_TEAM& chessTeam) {
  this->chessType = chessType;
  this->chessTeam = chessTeam;
}