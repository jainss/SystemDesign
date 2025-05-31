#pragma once
#include "strategies/Interface/PaymentStrategy.hpp"

class PaymentContext {
private:
    PaymentStrategy* strategy;

public:
    explicit PaymentContext(PaymentStrategy* paymentStrategy)
        : strategy(paymentStrategy) {}

    void setStrategy(PaymentStrategy* paymentStrategy) {
        strategy = paymentStrategy;
    }

    void makePayment(double amount) {
        if (strategy) {
            strategy->pay(amount);
        }
    }
    
    PaymentStrategy* getStrategy() {
        return strategy;
    }
};
