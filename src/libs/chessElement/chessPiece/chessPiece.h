#ifndef __CHESS_PIECE_H
#define __CHESS_PIECE_H
#include <enums/chessPieceEnum/chessPieceEnum.h>
#include <enums/chessTeamEnum/chessTeamEnum.h>

class ChessPiece {
 public:
  CHESS_PIECE chessPiece;
  CHESS_TEAM chessTeam;

  ChessPiece(const CHESS_PIECE& chessPiece, const CHESS_TEAM& chessTeam);
};
#endif