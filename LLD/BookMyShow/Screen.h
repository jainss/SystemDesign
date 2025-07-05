#pragma once

#include <vector>
#include <memory>
#include "Seat.h"  // Make sure to define this class or struct

class Screen {
private:
    int screenId;
    std::vector<std::shared_ptr<Seat>> seats;

public:

    Screen(int id, const std::vector<std::shared_ptr<Seat>>& seatList)
        : screenId(id), seats(seatList) {}

    int getScreenId() const {
        return screenId;
    }

    void setScreenId(int id) {
        screenId = id;
    }

    std::vector<std::shared_ptr<Seat>>& getSeats() {
        return seats;
    }

    void setSeats(const std::vector<std::shared_ptr<Seat>>& seatList) {
        seats = seatList;
    }
};
