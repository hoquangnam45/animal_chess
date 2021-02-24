#ifndef __CHESS_BOARD_H
#define __CHESS_BOARD_H
#include <chessElement/chessCell/chessCell.h>
class ChessBoard {
 public:
  const int BOARD_WIDTH = 7;
  const int BOARD_HEIGHT = 9;
  const ChessCell** boardCell;
  ChessBoard& operator=(const ChessBoard& b);
};

static ChessBoard chessBoard;
#endif  // !__CHESS_BOARD_H