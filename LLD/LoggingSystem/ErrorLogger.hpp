#pragma once
#include "Logger.hpp"
#include <memory>
#include <iostream>

class ErrorLogger : public Logger {
    public:
      ErrorLogger(std::shared_ptr<Logger> nextLogger=nullptr): Logger(nextLogger) {}

      void log(std::string level, const std::string& message){
        if(level == "ERROR") {
          std::cout << "ERROR: " << message << std::endl;
        } else {
          Logger::log(level, message);
        }
      }
};