#include "chessBoard.h"

void ChessBoard::addCell(const ChessPosition &chessPosition, const CHESS_TERRAIN &chessTerrain, const ChessPiece& chessPiece) {
    ChessCell& ref = boardArray.at(chessPosition.m_row).at(chessPosition.m_col); // This has bound checking
    ref.chessPosition = chessPosition;
    ref.chessTerrain = chessTerrain;
    ref.standingPiece = std::make_unique<ChessPiece>(chessPiece);
}