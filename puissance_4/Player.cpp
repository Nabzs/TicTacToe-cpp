#include "Player.h"
#include <iostream>

Player initialize_player(char taken_symbol) {
    Player player;
    std::cout << "Entrez le nom du joueur : ";
    std::cin >> player.name;

    bool valid_symbol = false;

    while (!valid_symbol) {
        std::cout << "Choisissez un symbole (X ou O) : ";
        std::cin >> player.symbol;

        if ((player.symbol == 'X' || player.symbol == 'O') && player.symbol != taken_symbol) {
            valid_symbol = true;
        } else if (player.symbol == taken_symbol) {
            std::cout << "Ce symbole est déjà pris. Choisissez-en un autre.\n";
        } else {
            std::cout << "Symbole invalide. Choisissez X ou O.\n";
        }
    }

    return player;
}
