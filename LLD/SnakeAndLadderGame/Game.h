#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <deque>
#include <memory>
#include "Board.h"
#include "Dice.h"
#include "Player.h"

class Game {
private:
    Board board;
    Dice dice;
    std::deque<std::shared_ptr<Player>> players;
    std::shared_ptr<Player> winner;

public:
    Game() : board(10, 5, 4), dice(1, 6), winner(nullptr) {
        addPlayers();
    }

    void addPlayers() {
        players.push_back(std::make_shared<Player>("Player 1"));
        players.push_back(std::make_shared<Player>("Player 2"));
    }

    void startGame() {
        int boardLimit = board.getBoardSize() * board.getBoardSize() - 1;

        while (!winner) {
            auto currentPlayer = getNextPlayer();
            std::cout << currentPlayer->id << "'s turn (Current Position: "
                      << currentPlayer->currentPosition << ")\n";

            int diceValue = dice.rollDice();
            std::cout << "Rolled a " << diceValue << std::endl;

            int newPos = currentPlayer->currentPosition + diceValue;
            if (newPos > boardLimit) newPos = currentPlayer->currentPosition;

            newPos = applyJumpIfAny(newPos);
            currentPlayer->currentPosition = newPos;

            std::cout << currentPlayer->id << " moved to " << newPos << "\n\n";

            if (newPos == boardLimit) {
                winner = currentPlayer;
            }
        }

        std::cout << "🏆 WINNER IS: " << winner->id << " 🎉\n";
    }

private:
    std::shared_ptr<Player> getNextPlayer() {
        auto front = players.front();
        players.pop_front();
        players.push_back(front);
        return front;
    }

    int applyJumpIfAny(int position) {
        Cell& cell = board.getCell(position);
        if (cell.jump && cell.jump->start == position) {
            std::string type = (cell.jump->end > cell.jump->start) ? "LADDER" : "SNAKE";
            std::cout << "🎯 Hit a " << type << "! Jumping from "
                      << cell.jump->start << " to " << cell.jump->end << std::endl;
            return cell.jump->end;
        }
        return position;
    }
};

#endif
