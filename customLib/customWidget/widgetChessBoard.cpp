#include "widgetChessBoard.h"
#include "../chessElement/ChessPieceFactory.h"
#include <algorithm>

widgetChessBoard* widgetChessBoard::initBoard() {
    widgetChessBoard* chessBoard = new widgetChessBoard();
    ChessCell newBoardTerrain[widgetChessBoard::NUM_ROW * widgetChessBoard::NUM_COL] = {
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::GOAL, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND,
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND,
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND,
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND,
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND,
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND, CHESS_TERRAIN::WATER, CHESS_TERRAIN::WATER, CHESS_TERRAIN::LAND,
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND,
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND,
        CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::GOAL, CHESS_TERRAIN::TRAP, CHESS_TERRAIN::LAND, CHESS_TERRAIN::LAND,
    };
    std::copy(std::begin(newBoardTerrain), std::end(newBoardTerrain), std::begin(chessBoard->board));
    ChessPieceFactory blueTeamFactory(CHESS_TEAM::BLUE);
    ChessPieceFactory redTeamFactory(CHESS_TEAM::RED);
    ChessCell newBoardChessPiece[widgetChessBoard::NUM_ROW * widgetChessBoard::NUM_COL] = {
        blueTeamFactory.get(CHESS_PIECE::LION), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(CHESS_PIECE::TIGER),
        blueTeamFactory.get(), blueTeamFactory.get(CHESS_PIECE::DOG), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(CHESS_PIECE::CAT), blueTeamFactory.get(),
        blueTeamFactory.get(CHESS_PIECE::MOUSE), blueTeamFactory.get(), blueTeamFactory.get(CHESS_PIECE::LEOPARD), blueTeamFactory.get(), blueTeamFactory.get(CHESS_PIECE::WOLF), blueTeamFactory.get(), blueTeamFactory.get(CHESS_PIECE::ELEPHANT),
        
        blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(),
        blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(),
        blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(), blueTeamFactory.get(),

        redTeamFactory.get(CHESS_PIECE::ELEPHANT), redTeamFactory.get(), redTeamFactory.get(CHESS_PIECE::WOLF), redTeamFactory.get(), redTeamFactory.get(CHESS_PIECE::LEOPARD), redTeamFactory.get(), redTeamFactory.get(CHESS_PIECE::MOUSE),
        redTeamFactory.get(), redTeamFactory.get(CHESS_PIECE::CAT), redTeamFactory.get(), redTeamFactory.get(), redTeamFactory.get(), redTeamFactory.get(CHESS_PIECE::DOG), redTeamFactory.get(),
        redTeamFactory.get(CHESS_PIECE::TIGER), redTeamFactory.get(), redTeamFactory.get(), redTeamFactory.get(), redTeamFactory.get(), redTeamFactory.get(), redTeamFactory.get(CHESS_PIECE::LION),
    };
    std::copy(std::begin(newBoardTerrain), std::end(newBoardTerrain), std::begin(chessBoard->board));
    return chessBoard;
};