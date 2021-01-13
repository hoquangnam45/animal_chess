#include "chessCell.h"

ChessCell::ChessCell(CHESS_TERRAIN chessTerrain){
    this->standingPiece = nullptr;
    this->chessTerrain = chessTerrain;
}

ChessCell::ChessCell(ChessPiece* chessPiece){
    this->standingPiece = chessPiece;
} 