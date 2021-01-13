#include "ChessPieceFactory.h"

ChessPieceFactory::ChessPieceFactory(CHESS_TEAM chessTeam){
    this->chessTeam = chessTeam;
}

ChessPiece* ChessPieceFactory::get(CHESS_PIECE chessPiece){
    return new ChessPiece(chessPiece, this->chessTeam);
}

ChessPiece* ChessPieceFactory::get() {
    return nullptr;
}