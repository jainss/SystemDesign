#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include "./Enums/SeatCategory."

int main() {
    // === Initialization ===
    // Movies
    Movie avengers = {1, "AVENGERS", 128};
    Movie baahubali = {2, "BAAHUBALI", 180};

    // Screens & Seats
    std::vector<Seat> seats;
    for (int i = 0; i < 100; ++i) {
        SeatCategory category;
        if (i < 40) category = SeatCategory::SILVER;
        else if (i < 70) category = SeatCategory::GOLD;
        else category = SeatCategory::PLATINUM;
        seats.push_back({i, category});
    }

    Screen screen1 = {1, seats};

    // Theatres
    Theatre inox = {1, City::Bangalore, {screen1}, {}};
    Show inoxShow1 = {1, &inox.screens[0], &avengers, 8};
    Show inoxShow2 = {2, &inox.screens[0], &baahubali, 16};
    inox.shows.push_back(inoxShow1);
    inox.shows.push_back(inoxShow2);

    Theatre pvr = {2, City::Delhi, {screen1}, {}};
    Show pvrShow1 = {3, &pvr.screens[0], &avengers, 13};
    Show pvrShow2 = {4, &pvr.screens[0], &baahubali, 20};
    pvr.shows.push_back(pvrShow1);
    pvr.shows.push_back(pvrShow2);

    std::vector<Theatre> allTheatres = {inox, pvr};
    std::vector<Movie> allMovies = {avengers, baahubali};

    // === Booking Logic ===
    City userCity = City::Bangalore;
    std::string desiredMovie = "BAAHUBALI";

    // 1. Get all movies in city (filter logic not applied since data is hardcoded)
    Movie* interestedMovie = nullptr;
    for (auto& movie : allMovies) {
        if (movie.movieName == desiredMovie) {
            interestedMovie = &movie;
            break;
        }
    }

    if (!interestedMovie) {
        std::cout << "Movie not found.\n";
        return 0;
    }

    // 2. Get all shows for that movie in the city
    std::vector<Show*> matchingShows;
    for (auto& theatre : allTheatres) {
        if (theatre.city == userCity) {
            for (auto& show : theatre.shows) {
                if (show.movie->movieName == desiredMovie) {
                    matchingShows.push_back(&show);
                }
            }
        }
    }

    if (matchingShows.empty()) {
        std::cout << "No shows found for movie in your city.\n";
        return 0;
    }

    // 3. Pick first show (simplified logic)
    Show* selectedShow = matchingShows[0];
    int seatNumber = 30;

    // 4. Check if seat is available
    if (std::find(selectedShow->bookedSeatIds.begin(), selectedShow->bookedSeatIds.end(), seatNumber)
        != selectedShow->bookedSeatIds.end()) {
        std::cout << "Seat already booked, try again.\n";
        return 0;
    }

    selectedShow->bookedSeatIds.push_back(seatNumber);

    // 5. Confirm booking
    Booking booking;
    booking.show = selectedShow;
    for (const auto& seat : selectedShow->screen->seats) {
        if (seat.seatId == seatNumber) {
            booking.bookedSeats.push_back(seat);
        }
    }

    std::cout << "BOOKING SUCCESSFUL for seat " << seatNumber << " in show ID " << selectedShow->showId << "\n";
    return 0;
}