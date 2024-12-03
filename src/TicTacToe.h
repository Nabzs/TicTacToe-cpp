#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Player.h"

const int BOARD_SIZE = 3; // taille du plateau

// initialise le plateau
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);

void draw_game_board(char board[BOARD_SIZE][BOARD_SIZE]);

bool check_winner(char board[BOARD_SIZE][BOARD_SIZE], char symbol);

// si le plateau est plein
bool is_board_full(char board[BOARD_SIZE][BOARD_SIZE]);

void play_turn(Player player, char board[BOARD_SIZE][BOARD_SIZE]);

void play_ia_turn(Player ai, char board[BOARD_SIZE][BOARD_SIZE]);

#endif
