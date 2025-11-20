#pragma once
#include "../VehicleA.hpp"

class Car : public VehicleA {
    public:
      void drive() {
        std::cout<< " Driving a Car on Land " << std::endl;
      }
};