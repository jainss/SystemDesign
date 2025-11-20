#pragma once
#include <vector>
#include <memory>
#include "Inventory.h"
#include "Coin.h"
#include "./VendingStates/State.h"
#include "./VendingStates/StateImplement/IdleState.h"

class VendingMachine {
private:
    std::shared_ptr<State> vendingMachineState;
    Inventory inventory;
    std::vector<Coin> coinList;

public:
    VendingMachine() : inventory(10) {
        vendingMachineState = std::make_shared<IdleState>();
    }

    std::shared_ptr<State> getVendingMachineState() {
        return vendingMachineState;
    }

    void setVendingMachineState(std::shared_ptr<State> newState) {
        vendingMachineState = newState;
    }

    Inventory& getInventory() {
        return inventory;
    }

    void setInventory(const Inventory& inv) {
        inventory = inv;
    }

    std::vector<Coin>& getCoinList() {
        return coinList;
    }

    void setCoinList(const std::vector<Coin>& coins) {
        coinList = coins;
    }
};