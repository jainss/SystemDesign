#include <iostream>
#include "PizzaTypes/Margherita.hpp"
#include "PizzaTypes/FarmHouse.hpp"
#include "PizzaToppings/Cheese.hpp"
#include "PizzaToppings/Olives.hpp"
#include "PizzaToppings/Jalapeno.hpp"
#include "PizzaSizes/LargeSize.hpp"
#include "PizzaSizes/RegularSize.hpp"

int main() {
    // Example 1: Large Margherita + Cheese + Olives

    IPizza* pizza1 = new LargeSize( new Olives( new Cheese( new Margherita())));
    std::cout << pizza1->getDescription() << " = Rs. " << pizza1->getCost() <<  std::endl;
    delete pizza1;
    // Example 2: Regular FarmHouse + Jalapeno + Cheese

    IPizza* pizza2 = new RegularSize( new Jalapeno( new Cheese( new FarmHouse())));
    std::cout << pizza2->getDescription() << " = Rs. " << pizza2->getCost() <<  std::endl;
    delete pizza2;

    return 0;
}