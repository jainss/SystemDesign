#pragma once
#include <string>
using namespace std;

enum class VehicleType { BIKE, CAR, TRUCK };

class Vehicle {
public:
    string number;
    VehicleType type;
    Vehicle(string num, VehicleType t) : number(num), type(t) {}
};
