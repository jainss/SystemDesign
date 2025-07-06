#pragma once
#include <iostream>
#include "./../State.h"
#include "./../../VendingMachine.h"
#include "HasMoneyState.h"

class IdleState: public State {
    public:
      IdleState() {
        cout << "Currently Vending machine is in IdleState\n";
      }

      void clickOnInsertCoinButton(VendingMachine& machine) override {
          machine->setVendingMachineState(new HasCoinState());
      }

      void clickOnStartProductSelectionButton(VendingMachine& machine) override {
        throw runtime_error("First you need to click on insert coin button");
      }
      void insertCoin(VendingMachine* machine, Coin coin) override {
        throw runtime_error("You cannot insert coin in IdleState");
    }

    void chooseProduct(VendingMachine* machine, int codeNumber) override {
        throw runtime_error("You cannot choose product in IdleState");
    }

    int getChange(int returnChangeMoney) override {
        throw runtime_error("You cannot get change in IdleState");
    }

    vector<Coin> refundFullMoney(VendingMachine* machine) override {
        throw runtime_error("You cannot get refunded in IdleState");
    }

    Item dispenseProduct(VendingMachine* machine, int codeNumber) override {
        throw runtime_error("Product cannot be dispensed in IdleState");
    }

    void updateInventory(VendingMachine* machine, const Item& item, int codeNumber) override {
        machine->getInventory().addItem(item, codeNumber);
    }
};