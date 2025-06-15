#pragma once
#include "types.h"

class ExternalDispatcher;

class ExternalButton {
    private:
      int floor;
      Direction dir;
      ExternalDispatcher* dispatcher;
    
    public:
      ExternalButton(int floor, Direction dir, ExternalDispatcher* dispatcher) : floor(floor), dir(dir), dispatcher(dispatcher){}

    void press();
};