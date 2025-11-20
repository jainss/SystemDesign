#pragma once
#include "../IPizza.hpp"

class Margherita : public IPizza {
    public:
        std::string getDescription() const override {
           return "Margherita";
        }

        double getCost() const override {
            return 150.0;
        }
};