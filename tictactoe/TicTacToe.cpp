#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

void initialize_board(std::vector<std::vector<std::string>> &board) {
    int count = 1;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            board[i][j] = std::to_string(count++);
        }
    }
}

void draw_game_board(const std::vector<std::vector<std::string>> &board) {
    std::cout << "\n";
    for (const auto &row : board) {
        for (const auto &cell : row) {
            std::cout << "| " << cell << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "\n";
}

bool check_winner(const std::vector<std::vector<std::string>> &board, const std::string &symbol, int board_size) {
    int win_condition = (board_size == 3) ? 3 : 4;

    // Vérif lignes et colonnes
    for (int i = 0; i < board_size; i++) {
        int row_count = 0, col_count = 0;
        for (int j = 0; j < board_size; j++) {
            // Lignes
            if (board[i][j] == symbol) {
                row_count++;
                if (row_count == win_condition) return true;
            } else {
                row_count = 0;
            }
            // Colonnes
            if (board[j][i] == symbol) {
                col_count++;
                if (col_count == win_condition) return true;
            } else {
                col_count = 0;
            }
        }
    }

    // Vérif diagonales
    for (int i = 0; i <= board_size - win_condition; i++) {
        for (int j = 0; j <= board_size - win_condition; j++) {
            int main_diag = 0, anti_diag = 0;
            for (int k = 0; k < win_condition; k++) {
                if (board[i + k][j + k] == symbol) {
                    main_diag++;
                    if (main_diag == win_condition) return true;
                } else {
                    main_diag = 0;
                }
                if (board[i + k][j + win_condition - k - 1] == symbol) {
                    anti_diag++;
                    if (anti_diag == win_condition) return true;
                } else {
                    anti_diag = 0;
                }
            }
        }
    }

    return false;
}

bool is_board_full(const std::vector<std::vector<std::string>> &board) {
    for (const auto &row : board) {
        for (const auto &cell : row) {
            if (cell != "X" && cell != "O") {
                return false;
            }
        }
    }
    return true;
}

void play_turn(Player player, std::vector<std::vector<std::string>> &board) {
    int position;
    bool valid_move = false;

    while (!valid_move) {
        std::cout << player.name << ", entrez un numero de case : ";
        std::cin >> position;
        int row = (position - 1) / board.size();
        int col = (position - 1) % board.size();

        if (board[row][col] != "X" && board[row][col] != "O") {
            board[row][col] = player.symbol;
            valid_move = true;
        } else {
            std::cout << "Case deja occupee, essayez a nouveau.\n";
        }
    }
}

void play_ia_turn(Player ai, std::vector<std::vector<std::string>> &board) {
    int position;
    bool valid_move = false;

    std::srand(std::time(0));

    while (!valid_move) {
        position = std::rand() % (board.size() * board.size()) + 1;
        int row = (position - 1) / board.size();
        int col = (position - 1) % board.size();

        if (board[row][col] != "X" && board[row][col] != "O") {
            board[row][col] = ai.symbol;
            valid_move = true;
        }
    }
    std::cout << "L'IA a joue sur la case " << position << ".\n";
}
