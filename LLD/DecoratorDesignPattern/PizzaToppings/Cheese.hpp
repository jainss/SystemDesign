#pragma once
#include "../PizzaDecorator.hpp"

class Cheese : public PizzaDecorator {
    public:
       Cheese(IPizza* p): PizzaDecorator(p) {}

       std::string getDescription() const override {
        return pizza->getDescription() + " + Cheese";
       }

       double getCost() const override {
        return pizza->getCost() + 40.0;
       }
};