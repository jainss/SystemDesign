#pragma once
#include <iostream>
#include "Item.h"

class ItemShelf {
private:
    int code;
    Item item;
    bool soldOut;

public:
    // Constructor
    ItemShelf(int code = 0, const Item& item = Item(), bool soldOut = false)
        : code(code), item(item), soldOut(soldOut) {}

    // Getters
    int getCode() const {
        return code;
    }

    Item getItem() const {
        return item;
    }

    bool isSoldOut() const {
        return soldOut;
    }

    // Setters
    void setCode(int newCode) {
        code = newCode;
    }

    void setItem(const Item& newItem) {
        item = newItem;
    }

    void setSoldOut(bool status) {
        soldOut = status;
    }
};
