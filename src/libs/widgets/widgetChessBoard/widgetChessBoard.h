#ifndef __WIDGET_CHESS_BOARD_H
#define __WIDGET_CHESS_BOARD_H
#include <chessElement/chessBoard/chessBoard.h>
#include <chessElement/chessCell/chessCell.h>
#include <ultilities/configurationParser/configurationParser.h>

#include <QWidget>
#include <algorithm>

class WidgetChessBoard : public QWidget {
 public:
  WidgetChessBoard(QWidget* parent = nullptr);
  ~WidgetChessBoard();

 private:
  void viewChessBoard();
  ChessBoard chessBoardController;
};
#endif