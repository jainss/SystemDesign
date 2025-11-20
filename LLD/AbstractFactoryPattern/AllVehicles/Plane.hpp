#pragma once
#include "../VehicleB.hpp"

class Plane : public VehicleB {
    public:
      void drive() {
        std::cout<< " Driving a Plane on Air " << std::endl;
      }
};