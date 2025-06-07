// Gate.cpp
#include "Gate.h"

std::shared_ptr<Ticket> Gate::processVehicle(
    std::shared_ptr<Vehicle> vehicle,
    std::vector<std::shared_ptr<Floor>>& floors,
    int& ticketId)
{
    for (auto& floor : floors) {
        auto spot = floor->getAvailableSpot(vehicle->type);
        if (spot) {
            spot->assignVehicle(vehicle);
            return std::make_shared<Ticket>(ticketId++, vehicle, spot, shared_from_this());
        }
    }
    return nullptr;  // No spot available
}
