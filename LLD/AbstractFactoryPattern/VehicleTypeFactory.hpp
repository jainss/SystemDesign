#pragma once
#include "./TypeOfVehicles/VehicleFactory.hpp"
#include "./TypeOfVehicles/LandVehicleFactory.hpp"
#include "./TypeOfVehicles/AirVehicleFactory.hpp"

class VehicleTypeFactory {
    public:
        static VehicleFactory* getFactory(const std::string& env) {
        if(env == "Land") {
            return new LandVehicleFactory();
        } else if(env == "Air") {
            return new AirVehicleFactory();
        } else {
            return nullptr;
        }
      }
}; 