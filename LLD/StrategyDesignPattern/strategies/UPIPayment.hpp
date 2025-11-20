#pragma once
#include "Interface/PaymentStrategy.hpp"
#include "Interface/OTPVerifiable.hpp"
#include <iostream>

class UPIPayment : public PaymentStrategy, public OTPVerifiable {
    public: 
        void pay(double amount) override {
            std::cout << "Amount " << amount << "is Paid by UPI" << std::endl;
        }
       
        void verifyOTP() override {
            std::cout << "✅ OTP Verified for UPI payment." << std::endl;
        }
};