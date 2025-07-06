#pragma once
#include "./../VendingMachine.h"

class State {
    virtual void clickOnInsertCoinButton(VendingMachine& machine) = 0;
    virtual void clickOnStartProductSelectionButton(VendingMachine& machine) = 0;
    virtual void insertCoin(VendingMachine& machine, const Coin& coin) = 0;
    virtual void chooseProduct(VendingMachine& machine, int codeNumber) = 0;
    virtual int getChange(int returnChangeMoney) = 0;
    virtual Item dispenseProduct(VendingMachine& machine, int codeNumber) = 0;
    virtual std::vector<Coin> refundFullMoney(VendingMachine& machine) = 0;
    virtual void updateInventory(VendingMachine& machine, const Item& item, int codeNumber) = 0;
};