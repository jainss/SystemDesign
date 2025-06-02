#pragma once
#include "Observer.hpp"
#include "./../Observable/Product.hpp"
#include <iostream>
#include <string>

class User: public Observer {
    private:
       std::string userName;
       Product* productName;
    
    public:
       User(const std::string& name, Product* p): userName(name), productName(p) {}

       void update() override{
           std:: cout << "Hello " << userName << ", your product name " << productName->getName()
                    << " is now is stock " << productName->getStock() << std::endl;
       }
};