#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int count = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '0' + count++;
        }
    }
}

void draw_game_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    std::cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "\n";
}

bool check_winner(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;
    return false;
}

bool is_board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void play_turn(Player player, char board[BOARD_SIZE][BOARD_SIZE]) {
    int position;
    bool valid_move = false;

    while (!valid_move) {
        std::cout << player.name << ", entrez un numero de case (1-9) : ";
        std::cin >> position;
        int row = (position - 1) / BOARD_SIZE;
        int col = (position - 1) % BOARD_SIZE;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player.symbol;
            valid_move = true;
        } else {
            std::cout << "Case deja occupee, essayez a nouveau.\n";
        }
    }
}

void play_ia_turn(Player ai, char board[BOARD_SIZE][BOARD_SIZE]) {
    int position;
    bool valid_move = false;

    std::srand(std::time(0));

    while (!valid_move) {
        position = std::rand() % 9 + 1;
        int row = (position - 1) / BOARD_SIZE;
        int col = (position - 1) % BOARD_SIZE;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = ai.symbol;
            valid_move = true;
        }
    }
    std::cout << "L'IA a joue sur la case " << position << ".\n";
}