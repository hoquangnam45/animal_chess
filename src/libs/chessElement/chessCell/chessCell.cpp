#include "chessCell.h"

ChessCell::ChessCell(const ChessPosition& chessPosition) {
  this->chessPosition = chessPosition;
}

ChessCell::~ChessCell() = default;

ChessCell::ChessCell(ChessCell&& b) noexcept: chessPosition(b.chessPosition), chessTerrain(b.chessTerrain), standingPiece(std::move(b.standingPiece)) {}

ChessCell::ChessCell(): chessTerrain(CHESS_TERRAIN::UNDEFINED) {}
