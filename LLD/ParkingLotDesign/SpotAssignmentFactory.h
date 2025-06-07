#pragma once
#include "Vehicle.h"
#include "SpotType.h"

class SpotAssignmentFactory {
public:
    static bool isCompatible(VehicleType vType, SpotType sType) {
        switch (vType) {
            case VehicleType::BIKE: return sType == SpotType::TWO_WHEELER;
            case VehicleType::CAR: return sType == SpotType::FOUR_WHEELER;
            case VehicleType::TRUCK: return sType == SpotType::HEAVY_WHEELER;
            default: return false;
        }
    }
};
