#include "Puissance4.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

void initialize_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = '.';
        }
    }
}

void display_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    std::cout << "\n";
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|\n";
    }
    for (int j = 0; j < BOARD_WIDTH; j++) {
        std::cout << "  " << j + 1 << " ";
    }
    std::cout << "\n\n";
}

bool check_winner(char board[BOARD_HEIGHT][BOARD_WIDTH], char symbol) {
    // Vérif si 4 pions sont alignées sur une meme ligne
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j <= BOARD_WIDTH - 4; j++) {
            if (board[i][j] == symbol && board[i][j + 1] == symbol &&
                board[i][j + 2] == symbol && board[i][j + 3] == symbol) {
                return true;
            }
        }
    }

    // Vérif si 4 pions sont alignées sur une meme collone
    for (int i = 0; i <= BOARD_HEIGHT - 4; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == symbol && board[i + 1][j] == symbol &&
                board[i + 2][j] == symbol && board[i + 3][j] == symbol) {
                return true;
            }
        }
    }

    // Vérif des diagonales (\)
    for (int i = 0; i <= BOARD_HEIGHT - 4; i++) {
        for (int j = 0; j <= BOARD_WIDTH - 4; j++) {
            if (board[i][j] == symbol && board[i + 1][j + 1] == symbol &&
                board[i + 2][j + 2] == symbol && board[i + 3][j + 3] == symbol) {
                return true;
            }
        }
    }

    // Vérif des diagonales (/)
    for (int i = 0; i <= BOARD_HEIGHT - 4; i++) {
        for (int j = 3; j < BOARD_WIDTH; j++) {
            if (board[i][j] == symbol && board[i + 1][j - 1] == symbol &&
                board[i + 2][j - 2] == symbol && board[i + 3][j - 3] == symbol) {
                return true;
            }
        }
    }

    return false;
}

bool is_board_full(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
        if (board[0][j] == '.') {
            return false;
        }
    }
    return true;
}

void play_turn(Player player, char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    int column;
    bool valid_move = false;

    while (!valid_move) {
        std::cout << player.name << ", choisissez une colonne (1-" << BOARD_WIDTH << "): ";
        std::cin >> column;
        column--;

        if (column >= 0 && column < BOARD_WIDTH) {
            for (int i = BOARD_HEIGHT - 1; i >= 0; i--) {
                if (board[i][column] == '.') {
                    board[i][column] = player.symbol;
                    valid_move = true;
                    break;
                }
            }
            if (!valid_move) {
                std::cout << "Cette colonne est pleine. Essayez une autre.\n";
            }
        } else {
            std::cout << "Colonne invalide. Essayez à nouveau.\n";
        }
    }
}
