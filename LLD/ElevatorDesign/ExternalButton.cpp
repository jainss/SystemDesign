#include "ExternalButton.h"
#include "ExternalDispatcher.h"

void ExternalButton::press() {
    dispatcher->handleRequest(floor, direction);
}