#ifndef __CHESS_PIECE_ENUM_H
#define __CHESS_PIECE_ENUM_H
#include <map>
#include <string>
enum class CHESS_TYPE {
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

extern const std::map<std::string, CHESS_TYPE> CHESS_TYPE_DICTIONARY;
#endif