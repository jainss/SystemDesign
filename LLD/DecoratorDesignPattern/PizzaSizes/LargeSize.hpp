#pragma once
#include "../PizzaDecorator.hpp"

class LargeSize : public PizzaDecorator {
public:
    LargeSize(IPizza* p) : PizzaDecorator(p) {}

    std::string getDescription() const override {
        return "Large " + pizza->getDescription();
    }

    double getCost() const override {
        return pizza->getCost() + 50.0;
    }
};
