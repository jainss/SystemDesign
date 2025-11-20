#pragma once 
#include "VehicleFactory.hpp"
#include "../AllVehicles/Car.hpp"
#include "../AllVehicles/Truck.hpp"

class LandVehicleFactory: public VehicleFactory {
   public:
    VehicleA* createVehicleA() override {
        return new Car();
    }

    VehicleB* createVehicleB() override {
        return new Truck();
    }
};