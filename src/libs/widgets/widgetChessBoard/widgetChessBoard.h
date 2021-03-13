#ifndef __WIDGET_CHESS_BOARD_H
#define __WIDGET_CHESS_BOARD_H
#include <chessElement/chessCell/chessCell.h>
#include <chessElement/chessBoard/chessBoard.h>
#include <QWidget>
#include <algorithm>

extern ChessBoard chessBoard;
class WidgetChessBoard {
 public:
  static WidgetChessBoard* initBoard() { return nullptr; };
  WidgetChessBoard(QWidget* parent);
  ~WidgetChessBoard();

 private:
  WidgetChessBoard(){};
  void viewChessBoard();
};
#endif