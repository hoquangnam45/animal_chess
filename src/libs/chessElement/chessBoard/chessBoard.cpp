#include "chessBoard.h"

void ChessBoard::addCell(const ChessPosition &chessPosition, const CHESS_TERRAIN &chessTerrain, const ChessPiece& chessPiece) {
    ChessCell& ref = boardArray.at(chessPosition.m_row).at(chessPosition.m_col); // This has bound checking
    ref.chessPosition = chessPosition;
    ref.chessTerrain = chessTerrain;
    if (chessPiece.chessType != CHESS_TYPE::UNDEFINED && chessPiece.chessTeam != CHESS_TEAM::UNDEFINED) {
        ref.standingPiece = std::make_unique<ChessPiece>(chessPiece);
    }
}

ChessBoard::ChessBoard(ChessBoard&& board,
                       std::function<void(const ChessPosition &fromPos, const ChessPosition &toPos)> updateFn):
        updateFn(updateFn),
        boardArray(std::move(board.boardArray)) {}

void ChessBoard::movePiece(const ChessPosition &fromPos, const ChessPosition &toPos) {
    ChessCell& to = boardArray.at(toPos.m_row).at(toPos.m_col);
    if (fromPos == ChessPosition(-1, -1)) {
        assert(to.standingPiece != nullptr);
        updateFn(fromPos, toPos);
        return;
    }
    ChessCell& from = boardArray.at(fromPos.m_row).at(fromPos.m_col);
    if (from.standingPiece == nullptr || to.standingPiece != nullptr) {
        return;
    }
    to.standingPiece = std::move(from.standingPiece);
    updateFn(fromPos, toPos);
}
