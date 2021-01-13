#ifndef __WIDGET_CHESS_BOARD_H
#define __WIDGET_CHESS_BOARD_H
#include "../chessElement/chessCell.h"

class widgetChessBoard{
    public: 
        static widgetChessBoard* initBoard();
    private:
        const static int NUM_ROW = 9;
        const static int NUM_COL = 7;
        ChessCell board[widgetChessBoard::NUM_ROW * widgetChessBoard::NUM_COL];
        widgetChessBoard() {};
};
#endif