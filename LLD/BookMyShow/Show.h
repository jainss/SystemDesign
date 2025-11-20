#pragma once

#include <vector>
#include <memory>
#include "Movie.h"
#include "Screen.h"

class Show {
private:
    int showId;
    std::shared_ptr<Movie> movie;
    std::shared_ptr<Screen> screen;
    int showStartTime;  // You can use time_t or chrono later
    std::vector<int> bookedSeatIds;

public:

    Show(int id, std::shared_ptr<Movie> moviePtr, std::shared_ptr<Screen> screenPtr, int startTime)
        : showId(id), movie(std::move(moviePtr)), screen(std::move(screenPtr)), showStartTime(startTime) {}

    int getShowId() const {
        return showId;
    }

    void setShowId(int id) {
        showId = id;
    }

    std::shared_ptr<Movie> getMovie() const {
        return movie;
    }

    void setMovie(const std::shared_ptr<Movie>& moviePtr) {
        movie = moviePtr;
    }

    std::shared_ptr<Screen> getScreen() const {
        return screen;
    }

    void setScreen(const std::shared_ptr<Screen>& screenPtr) {
        screen = screenPtr;
    }

    int getShowStartTime() const {
        return showStartTime;
    }

    void setShowStartTime(int startTime) {
        showStartTime = startTime;
    }

    std::vector<int>& getBookedSeatIds() {
        return bookedSeatIds;
    }

    void setBookedSeatIds(const std::vector<int>& seats) {
        bookedSeatIds = seats;
    }

    void bookSeat(int seatId) {
        bookedSeatIds.push_back(seatId);
    }

    bool isSeatBooked(int seatId) const {
        return std::find(bookedSeatIds.begin(), bookedSeatIds.end(), seatId) != bookedSeatIds.end();
    }
};
