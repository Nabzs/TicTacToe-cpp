#include <iostream>
#include "Player.h"
#include "Puissance4.h"

int main() {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    initialize_board(board);

    std::cout << "Bienvenue dans Puissance 4\n";
    Player player1 = initialize_player(); // premier joueur
    Player player2 = initialize_player(player1.symbol); // deuxième joueur

    bool game_over = false;
    int turn = 0;

    while (!game_over) {
        display_board(board);
        if (turn % 2 == 0) {
            play_turn(player1, board);
        } else {
            play_turn(player2, board);
        }

        if (check_winner(board, (turn % 2 == 0) ? player1.symbol : player2.symbol)) {
            display_board(board);
            std::cout << "Felicitations ! " << ((turn % 2 == 0) ? player1.name : player2.name) << " a gagne \n";
            game_over = true;
        } else if (is_board_full(board)) {
            display_board(board);
            std::cout << "Match nul !\n";
            game_over = true;
        }

        turn++;
    }

    return 0;
}
