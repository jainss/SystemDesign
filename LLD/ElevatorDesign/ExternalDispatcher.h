// ExternalDispatcher.h
#pragma once
#include "ElevatorCar.h"

class ExternalDispatcher {
private:
    ElevatorCar* car;

public:
    ExternalDispatcher(ElevatorCar* c) : car(c) {}
    void handleRequest(int floor, Direction dir) {
        car->addRequest(floor);
    }
};
