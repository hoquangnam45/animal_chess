#ifndef __CHESS_PIECE_ENUM_H
#define __CHESS_PIECE_ENUM_H
#include <map>
#include <string>
enum class CHESS_PIECE {
  UNDEFINED,
  MOUSE,
  CAT,
  DOG,
  WOLF,
  LEOPARD,
  TIGER,
  LION,
  ELEPHANT,
};

extern const std::map<std::string, CHESS_PIECE> CHESS_PIECE_DICTIONARY;
#endif