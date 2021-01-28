#ifndef __CHESS_PIECE_H
#define __CHESS_PIECE_H
#include <enums/chessPieceEnum.h>
#include <enums/chessTeamEnum.h>

class ChessPiece {
 public:
  CHESS_PIECE chessPiece;
  CHESS_TEAM chessTeam;
  ChessPiece(CHESS_PIECE chessPiece, CHESS_TEAM chessTeam);
  ChessPiece(){};
};
#endif