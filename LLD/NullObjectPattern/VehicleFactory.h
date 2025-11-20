#pragma once
#include <memory>
#include "Car.h"
#include "NullVehicle.h"
#include "Vehicle.h"

class VehicleFactory {
    public:
      static std::shared_ptr<Vehicle> getVehicle(const std::string& type){
        if(type == "Car"){
            return std::make_shared<Car>();
        }else {
            return std::make_shared<NullVehicle>();
        }
      }
};