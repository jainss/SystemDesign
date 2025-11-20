#pragma once
#include "ElevatorCar.h"

class InternalDispatcher {
    private:
      ElevatorCar* car;

    public:
      InternalDispatcher(ElevatorCar* car) : car(car) {}
    
      void handleRequest(int floor) {
        car->addRequest(floor);
      }
};