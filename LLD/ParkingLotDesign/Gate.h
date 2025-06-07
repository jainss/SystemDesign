// Gate.h
#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Vehicle.h"

enum class GateType {
    ENTRY,
    EXIT
};

class Gate : public std::enable_shared_from_this<Gate> {
public:
    int id;
    std::string name;
    GateType type;  // ✅ Use the enum

    Gate(int id, GateType type) : id(id), type(type) {
        name = (type == GateType::ENTRY) ? "Entry Gate" : "Exit Gate";
    }

    std::shared_ptr<Ticket> processVehicle(
        std::shared_ptr<Vehicle> vehicle,
        std::vector<std::shared_ptr<Floor>>& floors,
        int& ticketId);
};
