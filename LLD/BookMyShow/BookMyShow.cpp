#include "MovieController.h"
#include "TheatreController.h"
#include "Booking.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

class BookMyShow {
private:
    MovieController movieController;
    TheatreController theatreController;

public:
    BookMyShow() = default;

    void initialize();
    void createBooking(City userCity, const std::string& movieName);

private:
    void createMovies();
    void createTheatre();
    std::vector<std::shared_ptr<Screen>> createScreen();
    std::shared_ptr<Show> createShow(int showId, std::shared_ptr<Screen> screen, std::shared_ptr<Movie> movie, int startTime);
    std::vector<std::shared_ptr<Seat>> createSeats();
};
