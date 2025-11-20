#include "InternalButton.h"
#include "InternalDispatcher.h"

void InternalButton::press() {
    dispatcher->handleRequest(targetFloor);
}