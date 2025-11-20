#include "PaymentService.h"

// Correctly define the static rateTable
std::unordered_map<VehicleType, RateCard> PaymentService::rateTable = {
    {VehicleType::BIKE,  RateCard(10, 30, 5)},
    {VehicleType::CAR,   RateCard(20, 60, 10)},
    {VehicleType::TRUCK, RateCard(50, 150, 20)}
};
