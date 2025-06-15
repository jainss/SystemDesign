#include <iostream>
#include <vector>
#include <memory>
#include "Store.hpp"
#include "Bill.hpp"

int main() {
    auto user1 = make_shared<User>(1, "Alice", "9999999999", "alice@example.com", "DL12345");
    time_t now = time(0);

    auto v1 = make_shared<Vehicle>(1, 101, VehicleType::CAR, "Toyota", "Innova", 15000, 15, 2000, 1500, 200, 5, now);
    auto v2 = make_shared<Vehicle>(2, 102, VehicleType::CAR, "Hyundai", "Creta", 12000, 14, 1800, 1400, 180, 5, now);
    vector<shared_ptr<Vehicle>> vehicles = {v1, v2};

    Location loc("Anu APpartmnet", 560001, "Bangalore", "Karnataka", "India");
    Store store(1, vehicles, loc);

    auto available = store.getVehicle(VehicleType::CAR);
    auto reservation = store.createReservation(available[0], user1);

    Bill bill(reservation);
    double total = bill.computeAmount();
    cout << "Total Bill: " << total << endl;

    auto payment = make_shared<PaymentDetails>(101, total, PaymentMode::ONLINE);
    reservation->paymentDetails = payment;
    bill.markPaid();

    std:: cout << "Payment of ₹" << payment->getAmountPaid()
         << " done via " << (payment->getPaymentMode() == PaymentMode::ONLINE ? "Online" : "Cash") << endl;


    store.completeReservation(reservation->reservationId);

    std:: cout << "User Reservation History: ";

    for(const auto& res : user1->getReservations()) {
        std:: cout << "- Reservation #" << res->reservationId << " for vehicle "
             << res->vehicle->getVehicleID() << " [Status: ";
        switch (res->reservationStatus) {
            case ReservationStatus::SCHEDULED: cout << "Scheduled"; break;
            case ReservationStatus::INPROGRESS: cout << "In Progress"; break;
            case ReservationStatus::COMPLETED: cout << "Completed"; break;
            case ReservationStatus::CANCELLED: cout << "Cancelled"; break;
        }
        cout << "]" << endl;
    }

    return 0;
}