#ifndef __CHESS_CELL_H
#define __CHESS_CELL_H

#include <chessElement/ChessPosition/chessPosition.h>
#include <chessElement/chessPiece/chessPiece.h>
#include <enums/chessTerrainEnum/chessTerrainEnum.h>

class ChessCell {
 public:
  ChessPiece* standingPiece;
  ChessPosition chessPosition;
  CHESS_TERRAIN chessTerrain;
  ChessCell(const CHESS_TERRAIN& chessTerrain,
            ChessPiece* chessPiece = nullptr);
  ChessCell() : ChessCell(CHESS_TERRAIN::UNDEFINED){};
  ~ChessCell();
};
#endif