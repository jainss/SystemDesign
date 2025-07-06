#include <vector>
#include <iostream>
#include "ItemShelf.h"

class Inventory {
    private:
      std::vector<ItemShelf> inventory;

    public:
      Inventory(int itemCount) {
        inventory.resize(itemCount);
        initializeEmptyInventory();
      }

      std::vector<ItemShelf>& getInventory() {
        return inventory;
      }

      void initializeEmptyInventory() {
        int startCode = 1;
        for (auto& item : inventory) {
          item.setCode(startCode++);
          item.setSoldOut(false);
        }
      }

      void addItem(const Item& item, int codeNumber) {
        for(auto& itemShelf : inventory){
          if(itemShelf.getCode()==codeNumber){
            if(itemShelf.isSoldOut()){
              itemShelf.setItem(item);
              itemShelf.setSoldOut(false);
              return;
            }else{
                throw std::runtime_error("Item already present. Cannot add again.");
            }
          }
        }
        throw std::runtime_error("Invalid code number.");
      }

      Item getItem(int codeNumber) {
        for (const auto& item : inventory) {
          if (item.getCode() == codeNumber) {
            if(item.isSoldOut()){
                throw std::runtime_error("Item is already sold out.");
            }else{
                return item.getItem();
            }
          }
        }
        throw std::runtime_error("Invalid code number.");
      }
      
      void updateSoldOutItem(int codeNumber) {
        for (auto& shelf : inventory) {
            if (shelf.getCode() == codeNumber) {
                shelf.setSoldOut(true);
                return;
            }
        }
      }
};