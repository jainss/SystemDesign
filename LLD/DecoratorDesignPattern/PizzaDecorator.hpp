#pragma once
#include "./IPizza.hpp"

class PizzaDecorator : public IPizza {
    protected:
       IPizza* pizza;
    
    public:
       PizzaDecorator(IPizza* pizzaType) : pizza(pizzaType) {}
       virtual ~PizzaDecorator() {
        delete pizza;
       }
};