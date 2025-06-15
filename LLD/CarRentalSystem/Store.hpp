#pragma once
#include <vector>
#include <memory>
#include "VehicleInventoryManagement.hpp"
#include "Reservation.hpp"
#include "Location.hpp"
#include "Enums.hpp"
using namespace std;

class Store {
    private:
      int storeId;
      Location location;
      VehicleInventoryManagement inventory;
      vector<shared_ptr<Reservation>> reservations;

    public:
      Store(int id, const vector<shared_ptr<Vehicle>>& vehicles, Location loc) : storeId(id), location(loc), inventory(vehicles) {}
      
      vector<shared_ptr<Vehicle>> getVehicle (VehicleType type) {
        return inventory.getVehicleByType(type);
      }

      shared_ptr<Reservation> createReservation(shared_ptr<Vehicle> vehicle, shared_ptr<User> user) {
        auto reservation =make_shared<Reservation>(user, vehicle, location, location, ReservationType::DAILY);
        reservations.push_back(reservation);
        user->addReservation(reservation);
        vehicle->setStatus(Status::INACTIVE);
        return reservation;
      }

      void completeReservation(int reservationId) {
        for (auto& r : reservations) {
            if (r->reservationId == reservationId) {
                r->reservationStatus = ReservationStatus::COMPLETED;
                r->vehicle->setStatus(Status::ACTIVE);
            }
        }
      }

      int getStoreId() const {
        return storeId;
      }

      Location getLocation() const {
        return location;
      }

      VehicleInventoryManagement getInventory() const {
        return inventory;
      }
};