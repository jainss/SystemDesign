#pragma once
#include <string>
#include "PlayingPiece.hpp"

class Player {
private:
    std::string name;
    PlayingPiece piece;

public:
    Player(const std::string& name, const PlayingPiece& piece);
    std::string getName() const;
    PlayingPiece getPiece() const;
};