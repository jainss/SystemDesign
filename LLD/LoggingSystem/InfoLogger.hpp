#pragma once
#include "Logger.hpp"
#include <memory>
#include <iostream>

class InfoLogger: public Logger {
    public:
      InfoLogger(std::shared_ptr<Logger> nextLogger=nullptr): Logger(nextLogger) {}

      void log(std::string level, const std::string& message){
        if(level == "INFO") {
          std::cout << "INFO: " << message << std::endl;
        } else {
          Logger::log(level, message);
        }
      }
};