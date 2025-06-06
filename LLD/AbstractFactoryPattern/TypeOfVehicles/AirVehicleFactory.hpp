#pragma once 
#include "VehicleFactory.hpp"
#include "../AllVehicles/Plane.hpp"
#include "../AllVehicles/Helicopter.hpp"

class AirVehicleFactory: public VehicleFactory {
   public:
    VehicleA* createVehicleA() override {
        return new Helicopter();
    }

    VehicleB* createVehicleB() override {
        return new Plane();
    }
};