#pragma once
#include "ExternalButton.h"
#include "ExternalDispatcher.h"

class Floor {
  private:
    int floorNumber;
    ExternalButton upButton;
    ExternalButton downButton;

  public:
    Floor(int floor, ExternalDispatcher* dispatcher): floorNumber(floor), upButton(floor, Direction::UP, dispatcher),
        downButton(floor, Direction::DOWN, dispatcher) {}

    void pressUp() { upButton.press(); }
    void pressDown() { downButton.press(); }
};