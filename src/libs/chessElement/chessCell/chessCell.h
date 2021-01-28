#ifndef __CHESS_CELL_H
#define __CHESS_CELL_H

#include <chessElement/chessPiece/chessPiece.h>
#include <enums/chessTerrainEnum.h>

class ChessCell {
 public:
  ChessPiece* standingPiece;
  CHESS_TERRAIN chessTerrain;
  ChessCell(CHESS_TERRAIN chessTerrain);
  ChessCell(ChessPiece* chessPiece);
  ChessCell(){};
};
#endif