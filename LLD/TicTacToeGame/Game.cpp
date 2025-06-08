#include "Game.hpp"
#include <iostream>

Game::Game(int size) : board(size) {}

void Game::addPlayer(const std::string& name, char symbol) {
    players.emplace_back(name, PlayingPiece(symbol));
}

void Game::startGame() {
    while (true) {
        board.printBoard();
        Player currentPlayer = players.front();
        std::cout << currentPlayer.getName() << "'s turn (" << currentPlayer.getPiece().getSymbol() << ")\n";

        int row, col;
        std::cout << "Enter row and column: ";
        std::cin >> row >> col;

        if (!board.placePiece(row, col, currentPlayer.getPiece())) {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }

        if (board.checkWin(currentPlayer.getPiece())) {
            board.printBoard();
            std::cout << currentPlayer.getName() << " wins!\n";
            break;
        }

        if (board.isFull()) {
            board.printBoard();
            std::cout << "Game is a draw!\n";
            break;
        }

        players.pop_front();
        players.push_back(currentPlayer);
    }
}

