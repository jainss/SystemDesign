#pragma once

#include <memory>
#include <ctime>
#include "Vehicle.h"
#include "ParkingSpot.h"

class Gate; // 👈 Forward declaration ✅

class Ticket {
public:
    int id;
    std::shared_ptr<Vehicle> vehicle;
    std::shared_ptr<ParkingSpot> spot;
    std::shared_ptr<Gate> entryGate; // ✅ Now compiler knows what Gate is
    time_t entryTime;

    Ticket(int id, std::shared_ptr<Vehicle> v, std::shared_ptr<ParkingSpot> s, std::shared_ptr<Gate> g)
        : id(id), vehicle(v), spot(s), entryGate(g) {
        entryTime = time(nullptr);
    }
};
