#pragma once
#include <vector>
#include <memory>
#include "PlayingPiece.hpp"

class Board {
private:
    int size;
    std::vector<std::vector<std::shared_ptr<PlayingPiece>>> grid;

public:
    Board(int size);
    void printBoard();
    bool placePiece(int row, int col, const PlayingPiece& piece);
    bool checkWin(const PlayingPiece& piece);
    bool isFull();
};