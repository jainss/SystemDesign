#pragma once
#include <string>
#include "Enums.hpp"
using namespace std;

class Vehicle {
    private:
      int vehicleID, vehicleNumber, kmDriven, average, cc;
      int dailyRentalCost, hourlyRentalCost, noOfSeat;
      string companyName, modelName;
      time_t manufacturingDate;
      VehicleType vehicleType;
      Status status;
    
    public:
      Vehicle(int id, int number, VehicleType type, string company, string model,
            int kmDriven, int avg, int cc, int dailyCost, int hourlyCost, int seats,
            time_t mfgDate)
        : vehicleID(id), vehicleNumber(number), vehicleType(type), companyName(company),
          modelName(model), kmDriven(kmDriven), average(avg), cc(cc), dailyRentalCost(dailyCost),
          hourlyRentalCost(hourlyCost), noOfSeat(seats), manufacturingDate(mfgDate), status(Status::ACTIVE) {}

      int getVehicleID() const { return vehicleID; }
      VehicleType getVehicleType() const { return vehicleType; }
      Status getStatus() const { return status; }
      void setStatus(Status s) { status = s; }
};