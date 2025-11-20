/*
🧠 Why use dynamic_cast?
Because:
1. You don’t know the exact type of the strategy at compile time
2. You want to safely check if it supports something extra at runtime

🔒 Safety
If you used a regular static_cast, it would crash if the type didn’t match. dynamic_cast is safe — it gives you nullptr if it fails
*/

#include "PaymentContext.hpp"
#include "strategies/CreditCardPayment.hpp"
#include "strategies/DebitCardPayment.hpp"
#include "strategies/UPIPayment.hpp"

int main() {
    CreditCardPayment credit;
    DebitCardPayment debit;
    UPIPayment upi;

    PaymentContext context(&credit);
    context.makePayment(1000);  // Paid ₹1000 using Credit Card

    if(auto cashback = dynamic_cast<CashbackCapable*>(context.getStrategy())) {
        cashback->applyCashback();
    } 

    if(auto rewardPoint = dynamic_cast<RewardPoint*>(context.getStrategy())) {
        rewardPoint->giveRewardPoint();
    }

    std::cout << "------------------------" << std::endl;

    context.setStrategy(&debit);
    context.makePayment(500);   // Paid ₹500 using Debit Card

    if(auto rewardpoint = dynamic_cast<RewardPoint*>(context.getStrategy())) {
        rewardpoint->giveRewardPoint();
    } 
    
    std::cout << "------------------------" << std::endl;

    context.setStrategy(&upi);
    context.makePayment(250);   // Paid ₹250 using UPI

    if(auto otp = dynamic_cast<OTPVerifiable*>(context.getStrategy())) {
        otp->verifyOTP();
    }

    std::cout << "------------------------" << std::endl;
    return 0;
}