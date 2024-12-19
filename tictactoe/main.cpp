#include <iostream>
#include "Player.h"
#include "TicTacToe.h"
#include <string>

int main() {
    int board_size;
    do {
        std::cout << "Choisissez la taille du plateau (3, 4, ou 5) : ";
        std::cin >> board_size;
    } while (board_size < 3 || board_size > 5);

    std::vector<std::vector<std::string>> board(board_size, std::vector<std::string>(board_size));
    initialize_board(board);

    std::cout << "Bienvenue dans le jeu du TicTacToe\n";
    std::cout << "Veuillez choisir un mode de jeu :\n";
    std::cout << "1. Deux joueurs\n";
    std::cout << "2. Un joueur contre l'IA\n";

    int mode;
    std::cin >> mode;

    Player player1 = create_player();  // premier joueur
    Player player2;

    if (mode == 1) {
        player2 = create_player(player1.symbol);  // deuxième joueur
    } else { // mode IA
        player2.name = "IA";
        player2.symbol = (player1.symbol == "X") ? "O" : "X";
    }

    bool fin_partie = false;
    int turn = 0;

    while (!fin_partie) {
        draw_game_board(board);
        if (turn % 2 == 0) {
            play_turn(player1, board);
        } else {
            if (mode == 1) {
                play_turn(player2, board);
            } else {
                play_ia_turn(player2, board);
            }
        }

        if (check_winner(board, (turn % 2 == 0) ? player1.symbol : player2.symbol, board_size)) {
            draw_game_board(board);
            std::cout << ((turn % 2 == 0) ? player1.name : player2.name) << " a gagne !\n";
            fin_partie = true;
        } else if (is_board_full(board)) {
            draw_game_board(board);
            std::cout << "Match nul !\n";
            fin_partie = true;
        }

        turn++;
    }

    return 0;
}
