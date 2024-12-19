#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Player.h"

const int BOARD_SIZE = 3; // taille du plateau (On peux jouer sur un plateau de 3*3; 4*4 ou 5*5 )

// initialise le plateau
void initialize_board(std::string board[BOARD_SIZE][BOARD_SIZE]);

void draw_game_board(std::string board[BOARD_SIZE][BOARD_SIZE]);

bool check_winner(std::string board[BOARD_SIZE][BOARD_SIZE], std::string symbol);

// si le plateau est plein
bool is_board_full(std::string board[BOARD_SIZE][BOARD_SIZE]);

void play_turn(Player player, std::string board[BOARD_SIZE][BOARD_SIZE]);

void play_ia_turn(Player ai, std::string board[BOARD_SIZE][BOARD_SIZE]);

#endif