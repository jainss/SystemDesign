#pragma once
#include "../IPizza.hpp"

class FarmHouse : public IPizza {
public:
    std::string getDescription() const override {
        return "FarmHouse";
    }

    double getCost() const override {
        return 180.0;
    }
};
