#pragma once
#include <enums/chessTypeEnum/chessTypeEnum.h>
#include <enums/chessTeamEnum/chessTeamEnum.h>
#include <chessElement/ChessPosition/chessPosition.h>

class ChessPiece {
 public:
  CHESS_TYPE chessType = CHESS_TYPE::UNDEFINED;
  CHESS_TEAM chessTeam = CHESS_TEAM::UNDEFINED;
  ChessPiece(const CHESS_TYPE& chessType, const CHESS_TEAM& chessTeam);
};