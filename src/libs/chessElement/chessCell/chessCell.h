#ifndef __CHESS_CELL_H
#define __CHESS_CELL_H

#include <chessElement/chessPiece/chessPiece.h>
#include <enums/chessTerrainEnum/chessTerrainEnum.h>

class ChessCell {
 public:
  ChessPiece* standingPiece = nullptr;
  ChessPosition chessPosition;
  CHESS_TERRAIN chessTerrain = CHESS_TERRAIN::UNDEFINED;
  ChessCell(const ChessPosition& chessPostition);
  ChessCell();
  ~ChessCell();
};
#endif