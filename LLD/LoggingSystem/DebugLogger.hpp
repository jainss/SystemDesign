#pragma once
#include "Logger.hpp"
#include <memory>
#include <iostream>

class DebugLogger: public Logger {
    public:
      DebugLogger(std::shared_ptr<Logger> nextLogger=nullptr): Logger(nextLogger) {}

      void log(std::string level, const std::string& message){
        if(level == "DEBUG") {
          std::cout << "DEBUG: " << message << std::endl;
        } else {
          Logger::log(level, message);
        }
      }
};