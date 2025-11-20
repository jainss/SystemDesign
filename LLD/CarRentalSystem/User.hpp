#pragma once
#include <string>
#include <memory>
using namespace std;

class Reservation;

class User {
    private:
      int userId;
      string name, phone, email, drivingLicense;
      vector<shared_ptr<Reservation>> reservations;

    public:
      User(int id, string name, string phone, string email, string drivingLicense): name(name), phone(phone), email(email), drivingLicense(drivingLicense) {}
      string getName() { return name; }
      string getPhone() { return phone; }
      string getEmail() { return email; }
      string getDrivingLicense() { return drivingLicense; }

      void addReservation(shared_ptr<Reservation> res) {
        reservations.push_back(res);
      }

      const vector<shared_ptr<Reservation>>& getReservations() {
        return reservations;
      }
};
