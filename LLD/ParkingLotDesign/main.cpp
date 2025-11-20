#include "Floor.h"
#include "Gate.h"
#include "PaymentService.h"
#include "Receipt.h"
#include "PaymentMethod.h"
#include <iostream>
using namespace std;

int main() {
    vector<shared_ptr<Floor>> floors = {
        make_shared<Floor>(1),
        make_shared<Floor>(2)
    };

    floors[0]->spots.push_back(make_shared<ParkingSpot>(1, SpotType::TWO_WHEELER));
    floors[0]->spots.push_back(make_shared<ParkingSpot>(2, SpotType::FOUR_WHEELER));
    floors[1]->spots.push_back(make_shared<ParkingSpot>(3, SpotType::HEAVY_WHEELER));

    Gate entryGate(1, GateType::ENTRY);
    int ticketId = 1, receiptId = 1;

    auto bike = make_shared<Vehicle>("MH01BK1234", VehicleType::BIKE);
    auto ticket = entryGate.processVehicle(bike, floors, ticketId);
    if (!ticket) {
        cout << "No spot available for your vehicle.\n";
        return 0;
    }

    double fee = PaymentService::calculateAmount(ticket);
    auto method = make_shared<UpiPayment>();
    auto receipt = make_shared<Receipt>(receiptId++, ticket, fee, method);

    cout << "\n--- Receipt ---\n";
    cout << "Vehicle: " << bike->number << "\n";
    cout << "Fee: ₹" << receipt->amount << "\n";
    cout << receipt->paymentDetails << "\n";
    return 0;
}
