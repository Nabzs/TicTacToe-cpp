#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Player.h"
#include <vector>
#include <string>

const int BOARD_SIZE = 3; // taille du plateau (On peux jouer sur un plateau de 3*3; 4*4 ou 5*5)

// Création du plateau
void initialize_board(std::vector<std::vector<std::string>> &board);

// Affiche le plateau
void draw_game_board(const std::vector<std::vector<std::string>> &board);

// Vérif si un joueur a gagné
bool check_winner(const std::vector<std::vector<std::string>> &board, const std::string &symbol, int board_size);

// si le plateau est plein
bool is_board_full(const std::vector<std::vector<std::string>> &board);

// Permet de jouer son tour
void play_turn(Player player, std::vector<std::vector<std::string>> &board);

// Permet  a l'IA de jouer son tour
void play_ia_turn(Player ai, std::vector<std::vector<std::string>> &board);

#endif
