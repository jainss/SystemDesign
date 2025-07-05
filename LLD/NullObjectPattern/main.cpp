#include "VehicleFactory.h"
#include <iostream>
#include "Vehicle.h"

int main () {
    auto v1 = VehicleFactory::getVehicle("Car");
    auto v2 = VehicleFactory::getVehicle("Bike");

    std::cout << "Vehicle 1: " << v1->getType() << std::endl;
    v1->start();

    std::cout << "Vehicle 2: " << v2->getType() << std::endl;
    v2->start();

    return 0;
}