#ifndef __CHESS_TEAM_ENUM_H
#define __CHESS_TEAM_ENUM_H
#include <map>
#include <string>
enum class CHESS_TEAM { UNDEFINED, RED, BLUE };

extern const std::map<std::string, CHESS_TEAM> CHESS_TEAM_DICTIONARY;
#endif