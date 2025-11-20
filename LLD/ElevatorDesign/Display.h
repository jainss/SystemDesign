#pragma once
#include <iostream>
#include "types.h"

class Display {
    public: 
      void show(int floor, Direction dir) {
        std::string dirStr = (dir == Direction::UP) ? "UP" : (dir == Direction::DOWN) ? "DOWN" : "IDLE";
        std::cout << "[Display] Floor: " << floor << ", Direction: " << dirStr << "\n";
      }
};