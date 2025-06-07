#pragma once
#include "ParkingSpot.h"
#include "SpotAssignmentFactory.h"
#include <vector>
#include <memory>
using namespace std;

class Floor {
public:
    int id;
    vector<shared_ptr<ParkingSpot>> spots;

    Floor(int id) : id(id) {}

    shared_ptr<ParkingSpot> assignSpot(VehicleType type) {
        for (auto& s : spots) {
            if (!s->isFree) continue;
            if (SpotAssignmentFactory::isCompatible(type, s->spotType)) {
                s->isFree = false;
                return s;
            }
        }
        return nullptr;
    }
};
