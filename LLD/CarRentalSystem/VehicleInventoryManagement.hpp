#ifndef VEHICLE_INVENTORY_HPP
#define VEHICLE_INVENTORY_HPP
#pragma once
#include "Vehicle.hpp"
#include <memory>
#include <vector>
using namespace std;

class VehicleInventoryManagement {
    private:
      vector<shared_ptr<Vehicle>> vehicles;
    
    public:
      VehicleInventoryManagement(const vector<shared_ptr<Vehicle>>& v) : vehicles(v) {}

      vector<shared_ptr<Vehicle>> getVehicleByType (VehicleType type) {
        vector<shared_ptr<Vehicle>> result;
        for(auto& it: vehicles) {
            if(it->getStatus() == Status::ACTIVE && it->getVehicleType() == type){
                result.push_back(it);
            }
        }
        return result;
      }

      void addVehicle(shared_ptr<Vehicle> v) { 
        vehicles.push_back(v);
      }
};

#endif