#pragma once
#include "../VehicleA.hpp"

class Truck : public VehicleB {
    public:
      void drive() {
        std::cout<< " Driving a Truck on Land "<<  std::endl;
      }
};