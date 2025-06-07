#pragma once
#include <string>
using namespace std;

enum class PaymentType { UPI, CREDIT_CARD, DEBIT_CARD, CASH };

class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    virtual string pay(double amount) = 0;
};

class UpiPayment : public PaymentMethod {
public:
    string pay(double amount) override {
        return "Paid ₹" + to_string(amount) + " via UPI";
    }
};

class CreditCardPayment : public PaymentMethod {
public:
    string pay(double amount) override {
        return "Paid ₹" + to_string(amount) + " via Credit Card";
    }
};

class DebitCardPayment : public PaymentMethod {
public:
    string pay(double amount) override {
        return "Paid ₹" + to_string(amount) + " via Debit Card";
    }
};

class CashPayment : public PaymentMethod {
public:
    string pay(double amount) override {
        return "Paid ₹" + to_string(amount) + " in Cash";
    }
};
