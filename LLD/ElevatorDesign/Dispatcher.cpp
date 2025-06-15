#include "Dispatcher.h"
#include <iostream>

// ---- External Dispatcher ----
ExternalDispatcher::ExternalDispatcher(ElevatorCar* car)
    : elevator(car) {}

void ExternalDispatcher::submitExternalRequest(int floor) {
    std::cout << "[ExternalDispatcher] External request for floor " << floor << std::endl;
    elevator->addRequest(floor);
}

// ---- Internal Dispatcher ----
InternalDispatcher::InternalDispatcher(ElevatorCar* car)
    : elevator(car) {}

void InternalDispatcher::submitInternalRequest(int floor) {
    std::cout << "[InternalDispatcher] Internal request for floor " << floor << std::endl;
    elevator->addRequest(floor);
}
