#pragma once
#include "types.h"

class InternalDispatcher;

class InternalButton {
    private:
      int targetFloor;
      InternalDispatcher* dispatcher;
    
    public:
      InternalButton(int targetFloor, InternalDispatcher* dispatcher) : targetFloor(targetFloor), dispatcher(dispatcher){}

    void press();
};