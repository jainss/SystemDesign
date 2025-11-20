#pragma once
#include "Interface/PaymentStrategy.hpp"
#include "Interface/CashbackCapable.hpp"
#include "Interface/RewardPoint.hpp"
#include <iostream>

class CreditCardPayment : public PaymentStrategy, public CashbackCapable, public RewardPoint {
    public: 
        void pay(double amount) override {
            std::cout << "Amount " << amount << "is Paid by Credit Card" << std::endl;
        }

        void applyCashback() override {
            std::cout << "💰 Cashback applied for Credit Card payment." << std::endl;
        }

        void giveRewardPoint() override {
            std::cout << "🤑 Reward is Credited on your Credit Card" << std::endl;
        }
};