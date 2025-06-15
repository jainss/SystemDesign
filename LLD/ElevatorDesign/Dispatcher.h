#pragma once

#include "ElevatorCar.h"

class ExternalDispatcher {
private:
    ElevatorCar* elevator;
public:
    ExternalDispatcher(ElevatorCar* car);
    void submitExternalRequest(int floor);
};

class InternalDispatcher {
private:
    ElevatorCar* elevator;
public:
    InternalDispatcher(ElevatorCar* car);
    void submitInternalRequest(int floor);
};
