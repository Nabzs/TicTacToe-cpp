#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// Structure Player
struct Player {
    std::string name;
    char symbol;
};

Player create_player(char taken_symbol = '\0');

#endif
