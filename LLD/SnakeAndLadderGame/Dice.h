#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <ctime>

class Dice {
private:
    int minValue;
    int maxValue;

public:
    Dice(int minValue = 1, int maxValue = 6) : minValue(minValue), maxValue(maxValue) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    int rollDice() const {
        return (std::rand() % (maxValue - minValue + 1)) + minValue;
    }
};

#endif
