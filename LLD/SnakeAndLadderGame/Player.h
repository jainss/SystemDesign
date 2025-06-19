#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    std::string id;
    int currentPosition;

    Player(const std::string& id, int startPosition = 0)
        : id(id), currentPosition(startPosition) {}
};

#endif
