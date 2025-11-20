#pragma once
#include "./../Observer/Observer.hpp"
#include "Subject.hpp"
#include <vector>
#include <string>
#include <algorithm>

class Product: public Subject{
    private:
       std::vector<Observer*>observers;
       std::string productName;
       int quantity =0;
    
    public:
      Product(const std::string& name, int count): productName(name), quantity(count) {}

      void subscribeList(Observer* obs) override {
          observers.push_back(obs);
      }

      void unSubscribe(Observer* obs) override {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
      }

      void notify() override {
         for(Observer* obs: observers){
            obs->update();
         }
      }

      void setStock(int newStock) {
        quantity = newStock;
        notify();
      }

      int getStock() {
         return quantity;
      }

      std::string getName() {
         return productName;
      }
};