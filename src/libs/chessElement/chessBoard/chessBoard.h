#pragma once
#include <chessElement/chessCell/chessCell.h>
#include <array>
#include <memory>
#include <layout/chessBoardLayout.h>

class ChessBoard {
    private:
        // When you call movePiece, this function will also be used to update the widget, so that both will be in sync
        std::function<void(const ChessPosition& fromPos, const ChessPosition& toPos)> updateFn;
    public:
        ChessBoard(ChessBoard&& board, std::function<void(const ChessPosition &, const ChessPosition &)> updateFn);
        ChessBoard() = default;
        void addCell(const ChessPosition &chessPosition, const CHESS_TERRAIN &chessTerrain, const ChessPiece& chessPiece);
        std::array<std::array<ChessCell, ChessBoardLayout::BOARD_WIDTH>, ChessBoardLayout::BOARD_HEIGHT> boardArray;
        void movePiece(const ChessPosition &toPos, const ChessPosition &fromPos);
};
