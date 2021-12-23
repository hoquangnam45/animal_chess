#pragma once

#include <vector>
#include <libs/chessElement/ChessPosition/chessPosition.h>
#include <libs/chessElement/chessBoard/chessBoard.h>

class ValidMoveSuggester {
    public:
        static std::vector<ChessPosition> getValidMove(const ChessBoard& chessBoard, const ChessPiece& chessPiece);
};