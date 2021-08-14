#pragma once
#include <chessElement/chessCell/chessCell.h>
#include <array>
#include <memory>
#include <layout/chessBoardLayout.h>

class ChessBoard {
  public:
    void addCell(const ChessPosition &chessPosition, const CHESS_TERRAIN &chessTerrain, const ChessPiece& chessPiece);
    std::array<std::array<ChessCell, ChessBoardLayout::BOARD_WIDTH>, ChessBoardLayout::BOARD_HEIGHT> boardArray;
};
