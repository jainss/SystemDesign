#pragma once
#include <memory>
#include <ctime>
#include "User.hpp"
#include "Vehicle.hpp"
#include "Location.hpp"
#include "Enums.hpp"
#include "PaymentDetails.hpp"
using namespace std;

class Reservation {
    public:
      static int nextReservationId;
      int reservationId;
      shared_ptr<User> user;
      shared_ptr<Vehicle> vehicle;
      time_t bookingDate, dateBookedFrom, dateBookedTo;
      long fromTimeStamp, toTimeStamp;
      Location pickUpLocation, dropLocation;
      ReservationType reservationType;
      ReservationStatus reservationStatus;
      shared_ptr<PaymentDetails> paymentDetails;

      Reservation(shared_ptr<User> u, shared_ptr<Vehicle> v, Location pickup, Location drop,
            ReservationType type)
        : user(u), vehicle(v), pickUpLocation(pickup), dropLocation(drop), reservationType(type) {
        reservationId = nextReservationId++;
        time(&bookingDate);
        reservationStatus = ReservationStatus::SCHEDULED;
        dateBookedFrom = bookingDate;
        dateBookedTo = bookingDate + 86400; // 1 day default
        fromTimeStamp = bookingDate;
        toTimeStamp = dateBookedTo;
      }
};

int Reservation::nextReservationId = 1;