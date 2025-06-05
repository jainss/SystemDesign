#pragma once
#include <string>

class IPizza {
    public:
      virtual std::string getDescription() const = 0;
      virtual double getCost() const = 0;
      virtual ~IPizza() = default;
};