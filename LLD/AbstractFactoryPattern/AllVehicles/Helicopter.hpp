#pragma once
#include "../VehicleA.hpp"

class Helicopter : public VehicleA {
    public:
      void drive() {
        std::cout<< " Driving a Helicopter on Air " << std::endl;
      }
};