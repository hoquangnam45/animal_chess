#ifndef __CHESS_BOARD_H
#define __CHESS_BOARD_H
#include <chessElement/chessCell/chessCell.h>
#include <array>
#include <memory>

class ChessBoard {
  public:
    static const int BOARD_WIDTH = 7;
    static const int BOARD_HEIGHT = 9;
    static const std::array<std::array<CHESS_TERRAIN, BOARD_WIDTH>, BOARD_HEIGHT> CHESS_TERRAIN_MAP;
    ChessBoard();
    void addCell(const ChessCell& chessCell, ChessPiece* chessPiece = nullptr);
  private:
    std::array<std::array<ChessCell, BOARD_WIDTH>, BOARD_HEIGHT> boardArray;
};
#endif  // !__CHESS_BOARD_H