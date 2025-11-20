#pragma once
#include "../VehicleA.hpp"
#include "../VehicleB.hpp"

class VehicleFactory {
    public:
      virtual VehicleA* createVehicleA() =0;
      virtual VehicleB* createVehicleB() =0;
      virtual ~VehicleFactory() {};
};
