#pragma once
#include "./Enums/SeatCategory.h"

class Seat {
private:
    int seatId;
    int row;
    SeatCategory seatCategory;

public:
    Seat() = default;

    Seat(int id, int r, SeatCategory category)
        : seatId(id), row(r), seatCategory(category) {}

    int getSeatId() const {
        return seatId;
    }

    void setSeatId(int id) {
        seatId = id;
    }

    int getRow() const {
        return row;
    }

    void setRow(int r) {
        row = r;
    }

    SeatCategory getSeatCategory() const {
        return seatCategory;
    }

    void setSeatCategory(SeatCategory category) {
        seatCategory = category;
    }
};
 