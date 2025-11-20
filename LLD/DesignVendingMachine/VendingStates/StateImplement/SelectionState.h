#pragma once
#include <iostream>
#include "./../State.h"
#include "./../../VendingMachine.h"
#include "DispenseState.h"
#include "HasMoneyState.h"
#include "IdleState.h"

class SelectionState : public State {
  public:
    SelectionState() {
        cout << "Currently Vending machine is in SelectionState\n";
    }
    void clickOnInsertCoinButton(VendingMachine* machine) override {
        throw runtime_error("You cannot click on insert coin button in Selection state");
    }

    void clickOnStartProductSelectionButton(VendingMachine* machine) override {
        // no-op
    }

    void insertCoin(VendingMachine* machine, Coin coin) override {
        throw runtime_error("You cannot insert Coin in Selection state");
    }
    
    void chooseProduct(VendingMachine* machine, int codeNumber) override {
        Item item = machine->getInventory().getItem(codeNumber);

        int paidByUser =0;
        for(auto& coin : machine->getCoinList()){
            paidByUser+=coin.value;
        }
        if(paidByUser<item.price){
            cout << "Insufficient Amount, Product you selected is for price: " << item.price << " and you paid: " << paidByUser << "\n";
            refundFullMoney(machine);
            throw runtime_error("Insufficient amount");
        }else{
            if(paidByUser>item.price){
                getChange(paidByUser - item.price);
            }
            machine->setVendingMachineState(new DispenseState(machine, codeNumber));
        }
    }
    int getChange(int returnExtraMoney) override {
        cout << "Returned the change in the Coin Dispense Tray: " << returnExtraMoney << "\n";
        return returnExtraMoney;
    }

    vector<Coin> refundFullMoney(VendingMachine* machine) override {
        cout << "Returned the full amount back in the Coin Dispense Tray\n";
        machine->setVendingMachineState(new IdleState(machine));
        return machine->getCoinList();
    }

    Item dispenseProduct(VendingMachine* machine, int codeNumber) override {
        throw runtime_error("Product cannot be dispensed in Selection state");
    }

    void updateInventory(VendingMachine* machine, const Item& item, int codeNumber) override {
        throw runtime_error("Inventory cannot be updated in Selection state");
    }
};