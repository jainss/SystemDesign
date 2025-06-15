#include "DebugLogger.hpp"
#include "ErrorLogger.hpp"
#include "InfoLogger.hpp"
#include "Logger.hpp"
#include <memory>

int main() {
    std::shared_ptr<Logger> loggerChain =
        std::make_shared<InfoLogger>(
            std::make_shared<DebugLogger>(
                std::make_shared<ErrorLogger>()
            )
        );

    loggerChain->log("INFO", "Starting system...");
    loggerChain->log("DEBUG", "Debug initialized");
    loggerChain->log("ERROR", "Fatal exception occurred");

    return 0;
}