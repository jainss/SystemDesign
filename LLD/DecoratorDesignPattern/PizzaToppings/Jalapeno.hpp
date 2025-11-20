#pragma once
#include "../PizzaDecorator.hpp"

class Jalapeno : public PizzaDecorator {
public:
    Jalapeno(IPizza* p) : PizzaDecorator(p) {}

    std::string getDescription() const override {
        return pizza->getDescription() + " + Jalapeno";
    }

    double getCost() const override {
        return pizza->getCost() + 35.0;
    }
};
