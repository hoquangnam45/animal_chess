#ifndef __CHESS_POSITION_H
#define __CHESS_POSITION_H
class ChessPosition {
 public:
  int row;
  int column;
  ChessPosition() : ChessPosition(-1, - 1){};
  ChessPosition(int row, int column);
  ~ChessPosition();
};
#endif