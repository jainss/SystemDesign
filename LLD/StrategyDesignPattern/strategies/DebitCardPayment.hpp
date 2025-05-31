#pragma once
#include "Interface/PaymentStrategy.hpp"
#include "Interface/RewardPoint.hpp"
#include <iostream>

class DebitCardPayment : public PaymentStrategy, public RewardPoint {
    public: 
        void pay(double amount) override {
            std::cout << "Amount " << amount << "is paid by using Debit Card" << std::endl;
        }

        void giveRewardPoint() override {
            std::cout << "🤑 Reward on is Credited on your Debit Card" << std::endl;
        }
};