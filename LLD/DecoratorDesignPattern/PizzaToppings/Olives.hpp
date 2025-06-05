#pragma once
#include "../PizzaDecorator.hpp"

class Olives : public PizzaDecorator {
public:
    Olives(IPizza* p) : PizzaDecorator(p) {}

    std::string getDescription() const override {
        return pizza->getDescription() + " + Olives";
    }

    double getCost() const override {
        return pizza->getCost() + 30.0;
    }
};