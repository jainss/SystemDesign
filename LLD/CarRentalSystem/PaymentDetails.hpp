#include <ctime>
#include "Enums.hpp"

class PaymentDetails {
    private: 
      int paymentId;
      double amountPaid;
      time_t dateOfPayment;
      bool isRefundable;
      PaymentMode paymentMode;

    public: 
      PaymentDetails(int id, double amount, PaymentMode mode, bool refundable = false): paymentId(id), amountPaid(amount), paymentMode(mode), isRefundable(refundable) {}

      int getPaymentId() { return paymentId; }
      double getAmountPaid() { return amountPaid; }
      time_t getDateOfPayment() { return dateOfPayment; }
      PaymentMode getPaymentMode() { return paymentMode; }
};