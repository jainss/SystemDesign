#pragma once
#include "ItemType.h"

class Item {
    ItemType type;
    int price;
public:
    Item(ItemType type = ItemType::COKE, int price = 0) : type(type), price(price) {}

    ItemType getType() const { return type; }
    void setType(ItemType t) { type = t; }

    int getPrice() const { return price; }
    void setPrice(int p) { price = p; }
};