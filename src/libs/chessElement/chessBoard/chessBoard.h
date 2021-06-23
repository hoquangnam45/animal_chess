#ifndef __CHESS_BOARD_H
#define __CHESS_BOARD_H
#include <chessElement/chessCell/chessCell.h>

#include <array>
#include <memory>

class ChessBoard {
 public:
  ChessBoard();
  static const int BOARD_WIDTH = 7;
  static const int BOARD_HEIGHT = 9;
  std::array<ChessCell, 1> boardArray;
  ChessBoard& operator=(const ChessBoard& b);
};
#endif  // !__CHESS_BOARD_H