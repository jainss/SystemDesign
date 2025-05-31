#pragma once
#include <string>

/* We can make one Interface or strategy class and use that also but it have some pros and cons.
🧠 Pros: Simple
 ⚠️ Cons: Interface becomes cluttered if you add too many optional methods
 */

class PaymentStrategy {
    public:
        virtual void pay(double amount) = 0;
        virtual void applyCashback() = 0;
        virtual void giveRewardPoint() = 0;
        virtual void verifyOTP() = 0;
        virtual ~PaymentStrategy() = default;
};