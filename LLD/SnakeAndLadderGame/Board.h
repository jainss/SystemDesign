#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <random>
#include "Cell.h"
#include "Jump.h"

class Board {
private:
    std::vector<std::vector<Cell>> cells;
    int boardSize;

    int getRandomPosition(int min, int max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }

public:
    Board(int size, int numberOfSnakes, int numberOfLadders) : boardSize(size) {
        initializeCells();
        addSnakesAndLadders(numberOfSnakes, numberOfLadders);
    }

    void initializeCells() {
        cells.resize(boardSize, std::vector<Cell>(boardSize));
    }

    void addSnakesAndLadders(int snakes, int ladders) {
        int maxCell = boardSize * boardSize - 1;

        while (snakes--) {
            int head = getRandomPosition(2, maxCell);
            int tail = getRandomPosition(1, head - 1);
            getCell(head).jump = std::make_shared<Jump>(head, tail);
        }

        while (ladders--) {
            int start = getRandomPosition(1, maxCell - 1);
            int end = getRandomPosition(start + 1, maxCell);
            getCell(start).jump = std::make_shared<Jump>(start, end);
        }
    }

    Cell& getCell(int position) {
        int row = position / boardSize;
        int col = position % boardSize;
        return cells[row][col];
    }

    int getBoardSize() const {
        return boardSize;
    }
};

#endif
