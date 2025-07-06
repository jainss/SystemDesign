#include <iostream>
#include "VendingMachine.h"
#include "Item.h"
#include "ItemShelf.h"
#include "ItemType.h"
#include "Coin.h"
#include "./VendingStates/State.h"

void fillUpInventory(VendingMachine& vendingMachine) {
    auto& inventorySlots = vendingMachine.getInventory().getInventory();

    for (int i = 0; i < inventorySlots.size(); ++i) {
        Item newItem;
        if (i >= 0 && i < 3) {
            newItem.setType(ItemType::COKE);
            newItem.setPrice(12);
        } else if (i >= 3 && i < 5) {
            newItem.setType(ItemType::PEPSI);
            newItem.setPrice(9);
        } else if (i >= 5 && i < 7) {
            newItem.setType(ItemType::JUICE);
            newItem.setPrice(13);
        } else if (i >= 7 && i < 10) {
            newItem.setType(ItemType::SODA);
            newItem.setPrice(7);
        }

        inventorySlots[i].setItem(newItem);
        inventorySlots[i].setSoldOut(false);
    }
}

void displayInventory(VendingMachine& vendingMachine) {
    const auto& inventorySlots = vendingMachine.getInventory().getInventory();
    for (const auto& slot : inventorySlots) {
        std::cout << "CodeNumber: " << slot.getCode()
                  << " Item: " << itemTypeToString(slot.getItem().getType())
                  << " Price: " << slot.getItem().getPrice()
                  << " isAvailable: " << (!slot.isSoldOut() ? "true" : "false") << std::endl;
    }
}

int main() {
    VendingMachine vendingMachine;

    try {
        std::cout << "|\n";
        std::cout << "Filling up the inventory\n";
        std::cout << "|\n";

        fillUpInventory(vendingMachine);
        displayInventory(vendingMachine);

        std::cout << "|\n";
        std::cout << "Clicking on InsertCoinButton\n";
        std::cout << "|\n";

        auto state = vendingMachine.getVendingMachineState();
        state->clickOnInsertCoinButton(vendingMachine);

        state = vendingMachine.getVendingMachineState();
        state->insertCoin(vendingMachine, Coin::NICKEL);
        state->insertCoin(vendingMachine, Coin::QUARTER);

        std::cout << "|\n";
        std::cout << "Clicking on ProductSelectionButton\n";
        std::cout << "|\n";

        state->clickOnStartProductSelectionButton(vendingMachine);
        state = vendingMachine.getVendingMachineState();
        state->chooseProduct(vendingMachine, 102);

        displayInventory(vendingMachine);

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        displayInventory(vendingMachine);
    }

    return 0;
}

