#pragma once
#include "../PizzaDecorator.hpp"

class RegularSize : public PizzaDecorator {
public:
    RegularSize(IPizza* p) : PizzaDecorator(p) {}

    std::string getDescription() const override {
        return "Regular " + pizza->getDescription();
    }

    double getCost() const override {
        return pizza->getCost();  // no cost change
    }
};
