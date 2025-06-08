#pragma once

class PlayingPiece {
private:
    char symbol;

public:
    PlayingPiece(char symbol);
    char getSymbol() const;
};