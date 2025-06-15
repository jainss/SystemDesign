#pragma once
#include <memory>
#include <iostream>

class Logger {
    protected:
      std::shared_ptr<Logger> next;
    
    public:
      Logger(std::shared_ptr<Logger> nextLogger = nullptr): next(nextLogger) {}

      virtual void log(std::string level, const std::string& message) {
        if(next) {
          next->log(level, message);
        }else{
            std::cout<< "Nothing is there !!!";
        }
      }
      virtual ~Logger() {}
};