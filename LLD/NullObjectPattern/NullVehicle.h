#pragma once
#include "Vehicle.h"

class NullVehicle: public Vehicle {
    public:
      void start() override {
        std::cout << "No vehicle found to start!"  << std::endl;
      }

      std::string getType() override {
        return "NullVehicle";
      }
};