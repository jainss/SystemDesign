#pragma once
#include "SpotType.h"
#include "Vehicle.h"
#include <memory>

class ParkingSpot {
public:
    int id;
    SpotType spotType;
    bool isFree = true;
    shared_ptr<Vehicle> parkedVehicle = nullptr;

    ParkingSpot(int id, SpotType type) : id(id), spotType(type) {}
};
