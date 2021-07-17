#ifndef __CHESS_POSITION_H
#define __CHESS_POSITION_H
class ChessPosition {
 public:
  int row;
  int col;
  ChessPosition();
  ChessPosition(int row, int col);
  ~ChessPosition();
};
#endif