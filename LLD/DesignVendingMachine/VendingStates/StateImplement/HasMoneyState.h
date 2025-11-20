#pragma once
#include <iostream>
#include "./../State.h"
#include "./../../VendingMachine.h"
#include "IdleState.h"
#include "SelectionState.h"



class HasMoneyState: public State {
    public: 
      HasMoneyState() {
        cout << "Currently Vending machine is in HasMoneyState\n";
      }
      void clickOnInsertCoinButton(VendingMachine* machine) override {
        // do nothing
      }
      void clickOnStartProductSelectionButton(VendingMachine* machine) override {
        machine->setVendingMachineState(new SelectionState());
      }
      void insertCoin(VendingMachine* machine, Coin coin) override {
        cout << "Accepted the coin: " << coin.value << "\n";
        machine->getCoinList().push_back(coin);
      }
      void chooseProduct(VendingMachine* machine, int codeNumber) override {
        throw runtime_error("You need to click on start product selection button first");
      }

      int getChange(int returnChangeMoney) override {
        throw runtime_error("You cannot get change in HasMoney state");
      }

      Item dispenseProduct(VendingMachine* machine, int codeNumber) override {
        throw runtime_error("Product cannot be dispensed in HasMoney state");
      }

      vector<Coin> refundFullMoney(VendingMachine* machine) override {
        cout << "Returned the full amount back in the Coin Dispense Tray\n";
        machine->setVendingMachineState(new IdleState(machine));
        return machine->getCoinList();
      }

      void updateInventory(VendingMachine* machine, const Item& item, int codeNumber) override {
        throw runtime_error("You cannot update inventory in HasMoney state");
      }
};