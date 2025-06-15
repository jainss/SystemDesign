#include "ElevatorCar.h"
#include <iostream>
#include <unordered_set>
using namespace std;

ElevatorCar::ElevatorCar():currentFloor(0), direction(Direction::IDLE), doorState(DoorState::CLOSED) {}

void ElevatorCar::addRequest(int floor) {
    if (floor == currentFloor) {
        cout << "[ElevatorCar] Already at requested floor: " << floor << "\n";
        return;
    }
    if (direction == Direction::IDLE) {
        direction = (floor > currentFloor) ? Direction::UP : Direction::DOWN;
    }

    if (direction == Direction::UP) {
        if (floor > currentFloor)
            upQueue.push(floor);
        else
            pendingRequests.push_back(floor);
    } else if (direction == Direction::DOWN) {
        if (floor < currentFloor)
            downQueue.push(floor);
        else
            pendingRequests.push_back(floor);
    }
}

void ElevatorCar::processCurrentFloor() {
    bool stopped = false;
    if(direction == Direction::UP && !upQueue.empty() && currentFloor == upQueue.top()) {
        upQueue.pop();
        stopped = true;
    }else if(direction == Direction::DOWN && !downQueue.empty() && currentFloor == downQueue.top()){
        downQueue.pop();
        stopped = true;
    }

    if(stopped) {
        cout << "[ElevatorCar] Stopping at floor " << currentFloor << "\n";
    }
}

void ElevatorCar::rebuildQueuesFromPending() {
    unordered_set<int> visited;
    for(int floor: pendingRequests){
        if(visited.count(floor)){
            continue;
        }else{
            visited.insert(floor);
        }
        if(floor>currentFloor){
            upQueue.push(floor);
        }else if(floor<currentFloor){
            downQueue.push(floor);
        }
    }
    pendingRequests.clear();
}

void ElevatorCar::step() {
    display.show(currentFloor, direction);

    if(direction == Direction::UP && !upQueue.empty()) {
        currentFloor++;
    }else if(direction == Direction::DOWN && !downQueue.empty()){
        currentFloor--;
    }

    processCurrentFloor();

    if(direction == Direction::UP && upQueue.empty()){
        direction = Direction::DOWN;
        rebuildQueuesFromPending();
    } else if(direction == Direction::DOWN && downQueue.empty()){
        direction = Direction::UP;
        rebuildQueuesFromPending();
    }

    if (upQueue.empty() && downQueue.empty() && pendingRequests.empty()) {
        direction = Direction::IDLE;
    }
}

bool ElevatorCar::isIdle() const {
    return direction == Direction::IDLE && upQueue.empty() && downQueue.empty() && pendingRequests.empty();
}