#include "chessBoard.h"

const std::array<std::array<CHESS_TERRAIN, ChessBoard::BOARD_WIDTH>, ChessBoard::BOARD_HEIGHT> ChessBoard::CHESS_TERRAIN_MAP = 
{{
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::GOAL, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND}},
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND}},
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND}},
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND}},
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND}},
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND}},
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND}},
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND}},
    {{CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::GOAL, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND}},
}};

ChessBoard::ChessBoard(){};

void ChessBoard::addCell(const ChessCell& chessCell, ChessPiece* chessPiece) {
    int col = chessCell.chessPosition.col;
    int row = chessCell.chessPosition.row;
    boardArray.at(row).at(col) = chessCell; // This have bound checking
    ChessCell& ref = boardArray[row][col];
    ref.chessTerrain = CHESS_TERRAIN_MAP[row][col];
    ref.standingPiece = chessPiece;
}

