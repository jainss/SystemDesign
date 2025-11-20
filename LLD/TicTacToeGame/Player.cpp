#include "Player.hpp"

Player::Player(const std::string& name, const PlayingPiece& piece)
    : name(name), piece(piece) {}

std::string Player::getName() const { return name; }
PlayingPiece Player::getPiece() const { return piece; }