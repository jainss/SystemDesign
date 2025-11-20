#include "Board.hpp"
#include <iostream>

Board::Board(int size) : size(size) {
    grid.resize(size, std::vector<std::shared_ptr<PlayingPiece>>(size, nullptr));
}

void Board::printBoard() {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell) std::cout << cell->getSymbol() << " ";
            else std::cout << "- ";
        }
        std::cout << "\n";
    }
}

bool Board::placePiece(int row, int col, const PlayingPiece& piece) {
    if (row >= 0 && row < size && col >= 0 && col < size && !grid[row][col]) {
        grid[row][col] = std::make_shared<PlayingPiece>(piece);
        return true;
    }
    return false;
}

bool Board::isFull() {
    for (const auto& row : grid)
        for (const auto& cell : row)
            if (!cell) return false;
    return true;
}

bool Board::checkWin(const PlayingPiece& piece) {
    char sym = piece.getSymbol();
    // Check rows and columns
    for (int i = 0; i < size; ++i) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < size; ++j) {
            if (!grid[i][j] || grid[i][j]->getSymbol() != sym) rowWin = false;
            if (!grid[j][i] || grid[j][i]->getSymbol() != sym) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    // Diagonals
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < size; ++i) {
        if (!grid[i][i] || grid[i][i]->getSymbol() != sym) diag1 = false;
        if (!grid[i][size - i - 1] || grid[i][size - i - 1]->getSymbol() != sym) diag2 = false;
    }
    return diag1 || diag2;
}
