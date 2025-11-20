#pragma once
#include "types.h"
#include "Display.h"
#include <queue>
#include <vector>

class ElevatorCar {
    private:
      int currentFloor; 
      Direction direction;
      DoorState doorState;
      Display display;

      std::priority_queue<int, std::vector<int>, std::greater<int>> upQueue;
      std::priority_queue<int> downQueue;
      std::vector<int> pendingRequests;
      void processCurrentFloor();
      void rebuildQueuesFromPending();

    public:
      ElevatorCar();
      void addRequest(int floor);
      void step();
      bool isIdle() const;
};