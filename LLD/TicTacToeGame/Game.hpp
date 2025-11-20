#pragma once
#include <deque>
#include "Board.hpp"
#include "Player.hpp"

class Game {
private:
    Board board;
    std::deque<Player> players;

public:
    Game(int size);
    void addPlayer(const std::string& name, char symbol);
    void startGame();
};
