#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Player.h"

const int BOARD_SIZE = 5; // taille du plateau

// initialise le plateau
void initialize_board(std::string board[BOARD_SIZE][BOARD_SIZE]);

void draw_game_board(std::string board[BOARD_SIZE][BOARD_SIZE]);

bool check_winner(std::string board[BOARD_SIZE][BOARD_SIZE], std::string symbol);

// si le plateau est plein
bool is_board_full(std::string board[BOARD_SIZE][BOARD_SIZE]);

void play_turn(Player player, std::string board[BOARD_SIZE][BOARD_SIZE]);

void play_ia_turn(Player ai, std::string board[BOARD_SIZE][BOARD_SIZE]);

#endif