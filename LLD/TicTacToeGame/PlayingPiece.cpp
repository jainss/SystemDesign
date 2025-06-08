#include "PlayingPiece.hpp"

PlayingPiece::PlayingPiece(char symbol) : symbol(symbol) {}
char PlayingPiece::getSymbol() const { return symbol; }