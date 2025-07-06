#pragma once
#include <iostream>
#include <vector>
#include "./../State.h"
#include "IdleState.h"
#include "./../../VendingMachine.h"

class VendingMachine;

class DispenseState: public State {
    public:
      DispenseState(VendingMachine& machine, int codeNumber) {
        std::cout << "Currently Vending machine is in DispenseState\n";
      }
      void clickOnInsertCoinButton(VendingMachine& machine) override {
        throw std::runtime_error("Insert coin button cannot be clicked in Dispense state");
    }

    void clickOnStartProductSelectionButton(VendingMachine& machine) override {
        throw std::runtime_error("Product selection button cannot be clicked in Dispense state");
    }

    void insertCoin(VendingMachine& machine, const Coin& coin) override {
        throw std::runtime_error("Coin cannot be inserted in Dispense state");
    }

    void chooseProduct(VendingMachine& machine, int codeNumber) override {
        throw std::runtime_error("Product cannot be chosen in Dispense state");
    }

    int getChange(int returnChangeMoney) override {
        throw std::runtime_error("Change cannot be returned in Dispense state");
    }

    std::vector<Coin> refundFullMoney(VendingMachine& machine) override {
        throw std::runtime_error("Refund cannot happen in Dispense state");
    }

    Item dispenseProduct(VendingMachine& machine, int codeNumber) override {
        std::cout << "Product has been dispensed\n";
        Item item = machine.getInventory().getItem(codeNumber);
        machine.getInventory().updateSoldOutItem(codeNumber);
        machine.setVendingMachineState(new IdleState(&machine));
        return item;
    }

    void updateInventory(VendingMachine& machine, const Item& item, int codeNumber) override {
        throw runtime_error("Inventory cannot be updated in Dispense state");
    }
};