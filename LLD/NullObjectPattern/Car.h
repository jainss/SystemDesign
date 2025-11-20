#pragma once
#include "Vehicle.h"

class Car: public Vehicle{
    public:
      void start() override {
        std::cout << "Car started 🚗" << std::endl;
      }

      std::string getType() override {
        return "Car";
      }
};