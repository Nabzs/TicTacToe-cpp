#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#include "Player.h"

const int BOARD_HEIGHT = 6;
const int BOARD_WIDTH = 7;

//Ici pas besoin de mettre tous les types en std::string car je ne veux pas une taille adaptative

// Création du plateau
void initialize_board(char board[BOARD_HEIGHT][BOARD_WIDTH]);

// Affiche le plateau
void display_board(char board[BOARD_HEIGHT][BOARD_WIDTH]);

// Vérif si un joueur a gagné
bool check_winner(char board[BOARD_HEIGHT][BOARD_WIDTH], char symbol);

// Vérif si le plateau est plein
bool is_board_full(char board[BOARD_HEIGHT][BOARD_WIDTH]);

// Permet de jouer son tour
void play_turn(Player player, char board[BOARD_HEIGHT][BOARD_WIDTH]);

#endif
