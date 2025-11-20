#include <iostream>
#include <string>
#include "VehicleTypeFactory.hpp"
#include "TypeOfVehicles/VehicleFactory.hpp"
#include "VehicleA.hpp"
#include "VehicleB.hpp"

int main() {
    std::string userChoice;

    std::cout<< "Enter the vehicle Type you want (Land/Air) !!" << std::endl;
    std::cin>>userChoice;

    VehicleFactory* factory = VehicleTypeFactory::getFactory(userChoice);

    if(!factory){
        std::cout << "Invalid environment selected.\n";
        return 1;
    }
    VehicleA* vehicleA = factory->createVehicleA();
    VehicleB* vehicleB = factory->createVehicleB();

    vehicleA->drive();
    vehicleB->drive();

    delete factory;
    delete vehicleA;
    delete vehicleB;

    return 0;
};