#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// Struct Player
struct Player {
    std::string name;
    std::string symbol;
};

Player create_player(std::string taken_symbol = "\0");

#endif