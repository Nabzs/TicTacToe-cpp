#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

void initialize_board(std::string board[BOARD_SIZE][BOARD_SIZE]) {
    int count = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = std::to_string(count++) ;
        }
        
    }
}

void draw_game_board(std::string board[BOARD_SIZE][BOARD_SIZE]) {
    std::cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "\n";
}

bool check_winner(std::string board[BOARD_SIZE][BOARD_SIZE], std::string symbol) {
    // Nb symboles nécessaires pour gagner 
    //(3 si BOARD_SIZE = 3 et 4 si BOARD_SIZE = 4 ou 5)
    int win_condition = (BOARD_SIZE == 3) ? 3 : 4;

    // Vérification des lignes
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == symbol) {
                count++;
                if (count == win_condition) return true;
            } else {
                count = 0;
            }
        }
    }

    // Vérification des colonnes
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[j][i] == symbol) {
                count++;
                if (count == win_condition) return true;
            } else {
                count = 0;
            }
        }
    }

    // Vérification des diagonales
    for (int i = 0; i <= BOARD_SIZE - win_condition; i++) {
        for (int j = 0; j <= BOARD_SIZE - win_condition; j++) {
            int count_main_diag = 0;
            int count_anti_diag = 0;

            for (int k = 0; k < win_condition; k++) {
                // Diagonale principale
                if (board[i + k][j + k] == symbol) {
                    count_main_diag++;
                    if (count_main_diag == win_condition) return true;
                } else {
                    count_main_diag = 0;
                }

                // Diagonale secondaire
                if (board[i + k][j + win_condition - k - 1] == symbol) {
                    count_anti_diag++;
                    if (count_anti_diag == win_condition) return true;
                } else {
                    count_anti_diag = 0;
                }
            }
        }
    }

    // Match nul
    return false;
}



bool is_board_full(std::string board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != "X" && board[i][j] != "O") {
                return false;
            }
        }
    }
    return true;
}

void play_turn(Player player, std::string board[BOARD_SIZE][BOARD_SIZE]) {
    int position;
    bool valid_move = false;

    while (!valid_move) {
        std::cout << player.name << ", entrez un numero de case (1-9) : ";
        std::cin >> position;
        int row = (position - 1) / BOARD_SIZE;
        int col = (position - 1) % BOARD_SIZE;

        if (board[row][col] != "X" && board[row][col] != "O") {
            board[row][col] = player.symbol;
            valid_move = true;
        } else {
            std::cout << "Case deja occupee, essayez a nouveau.\n";
        }
    }
}

void play_ia_turn(Player ai, std::string board[BOARD_SIZE][BOARD_SIZE]) {
    int position;
    bool valid_move = false;

    std::srand(std::time(0));

    while (!valid_move) {
        position = std::rand() % 9 + 1;
        int row = (position - 1) / BOARD_SIZE;
        int col = (position - 1) % BOARD_SIZE;

        if (board[row][col] != "X" && board[row][col] != "O") {
            board[row][col] = ai.symbol;
            valid_move = true;
        }
    }
    std::cout << "L'IA a joue sur la case " << position << ".\n";
}