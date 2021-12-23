#pragma once
#include <enums/chessTypeEnum/chessTypeEnum.h>
#include <enums/chessTeamEnum/chessTeamEnum.h>
#include <chessElement/ChessPosition/chessPosition.h>

class ChessCell;

class ChessPiece {
 public:
  CHESS_TYPE chessType = CHESS_TYPE::UNDEFINED;
  CHESS_TEAM chessTeam = CHESS_TEAM::UNDEFINED;
  const ChessCell* chessCell;
  ChessPiece(const CHESS_TYPE& chessType, const CHESS_TEAM& chessTeam);
};