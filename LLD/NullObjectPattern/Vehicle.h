#pragma once
#include <iostream>
#include <string>

class Vehicle {
    public:
      virtual void start() =0;
      virtual std::string getType() =0;
      virtual ~Vehicle() {}
};