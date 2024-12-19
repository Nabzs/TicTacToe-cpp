#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// Struct Player
struct Player {
    std::string name;
    char symbol;
};

Player initialize_player(char taken_symbol = '\0');

#endif
