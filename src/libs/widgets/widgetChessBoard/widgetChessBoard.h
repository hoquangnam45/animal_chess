#ifndef __WIDGET_CHESS_BOARD_H
#define __WIDGET_CHESS_BOARD_H
#include <chessElement/chessCell/chessCell.h>

#include <QWidget>
#include <algorithm>

class WidgetChessBoard {
 public:
  static WidgetChessBoard* initBoard() { return nullptr; };
  WidgetChessBoard(QWidget* parent);
  ~WidgetChessBoard();

 private:
  const static int NUM_ROW = 9;
  const static int NUM_COL = 7;
  ChessCell board[WidgetChessBoard::NUM_ROW * WidgetChessBoard::NUM_COL];
  WidgetChessBoard(){};
  void setTerrain(char* filePath, ChessCell** chessBoard);
  void setChessPiece(char* filePath, ChessCell** chessBoard);
};
#endif