#ifndef __CHESS_PIECE_FACTORY_H
#define __CHESS_PIECE_FACTORY_H
#include "../enum/chessPieceEnum.h"
#include "../enum/chessTeamEnum.h"
#include "./chessPiece.h"

class ChessPieceFactory {
    private:
        CHESS_TEAM chessTeam;
    public:
        ChessPieceFactory(CHESS_TEAM chessTeam);
        ChessPiece* get(CHESS_PIECE chessPiece);
        ChessPiece* get();
        ChessPieceFactory(){};
};
#endif