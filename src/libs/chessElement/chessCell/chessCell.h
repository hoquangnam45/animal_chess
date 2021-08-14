#pragma once

#include <chessElement/chessPiece/chessPiece.h>
#include <enums/chessTerrainEnum/chessTerrainEnum.h>
#include <memory>

class ChessCell {
    public:
        std::unique_ptr<ChessPiece> standingPiece;
        ChessPosition chessPosition;
        CHESS_TERRAIN chessTerrain = CHESS_TERRAIN::UNDEFINED;
        explicit ChessCell(const ChessPosition& chessPosition);
        ChessCell(ChessCell&& b) noexcept;
        ChessCell();
        ~ChessCell();
};