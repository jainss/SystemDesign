#include "ElevatorCar.h"
#include "ExternalDispatcher.h"
#include "InternalDispatcher.h"
#include "InternalButton.h"
#include "Floor.h"

#include <vector>
#include <thread>
#include <chrono>

int main() {
    ElevatorCar car;
    InternalDispatcher internalDispatcher(&car);
    ExternalDispatcher externalDispatcher(&car);

    std::vector<Floor*> floors;
    for (int i = 0; i < 6; ++i) {
        floors.push_back(new Floor(i, &externalDispatcher));
    }

    std::vector<InternalButton*> internalButtons;
    for (int i = 0; i < 6; ++i) {
        internalButtons.push_back(new InternalButton(i, &internalDispatcher));
    }

    floors[0]->pressUp();     // Request from floor 0 to go up
    internalButtons[5]->press(); // Inside elevator, request to go to 5
    internalButtons[2]->press(); // Inside elevator, request to go to 2
    floors[4]->pressDown();   // Request from floor 4 to go down

    while (!car.isIdle()) {
        car.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
