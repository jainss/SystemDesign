#pragma once
#include "Ticket.h"
#include "PaymentMethod.h"
#include <string>
#include <memory>

class Receipt {
public:
    int id;
    time_t exitTime;
    double amount;
    string paymentDetails;
    shared_ptr<Ticket> ticket;

    Receipt(int rid, shared_ptr<Ticket> t, double amt, shared_ptr<PaymentMethod> method)
        : id(rid), ticket(t), amount(amt) {
        exitTime = time(nullptr);
        paymentDetails = method->pay(amt);
    }
};
