#include "Player.h"
#include <iostream>

// Définition de la fonction create_player (sans valeur par défaut ici)
Player create_player(char taken_symbol) {
    Player player;
    std::cout << "Entrez le nom du joueur : ";
    std::cin >> player.name;

    bool valid_symbol = false;

        // Si le joueur a choisi un nom deja pris rajouter un 2 derierre

    while (!valid_symbol) {
        std::cout << "Choisissez un symbole (X ou O) : ";
        std::cin >> player.symbol;

        // Si le symbole est valide et non pris
        if ((player.symbol == 'X' || player.symbol == 'O') && player.symbol != taken_symbol) {
            valid_symbol = true;
        } else if (player.symbol == taken_symbol) {
            std::cout << "Ce symbole est deja pris. Choisissez-en un autre.\n";
        } else {
            std::cout << "Symbole invalide. Choisissez X ou O.\n";
        }
    }

    return player;
}