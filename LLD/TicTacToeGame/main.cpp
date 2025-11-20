#include "Game.hpp"
#include <iostream>

int main() {
    int size;
    std::cout << "Enter board size: ";
    std::cin >> size;

    Game game(size);

    int numPlayers;
    std::cout << "Enter number of players: ";
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; ++i) {
        std::string name;
        char symbol;
        std::cout << "Enter name for player " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Enter symbol for " << name << ": ";
        std::cin >> symbol;
        game.addPlayer(name, symbol);
    }

    game.startGame();
    return 0;
}
