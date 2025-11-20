#pragma once
#include "Reservation.hpp"

class Bill {
    private:
      shared_ptr<Reservation> reservation;
      double totalAmount;
      bool paid;

    public:
      Bill(shared_ptr<Reservation> r)
        : reservation(r), paid(false) {
        totalAmount = computeAmount();
        }

      double computeAmount() {
        return 1000.0; // Placeholder
      }

      void markPaid() { paid = true; }

      bool isPaid() const { return paid; }
};