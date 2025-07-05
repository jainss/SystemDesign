#pragma once
#include <string>

class Movie {
private:
    int movieId;
    std::string movieName;
    int movieDurationInMinutes;

public:
    Movie() = default;

    Movie(int id, const std::string& name, int duration)
        : movieId(id), movieName(name), movieDurationInMinutes(duration) {}

    int getMovieId() const {
        return movieId;
    }

    void setMovieId(int id) {
        movieId = id;
    }

    std::string getName() const {
        return movieName;
    }

    void setName(const std::string& name) {
        movieName = name;
    }

    int getDuration() const {
        return movieDurationInMinutes;
    }

    void setDuration(int duration) {
        movieDurationInMinutes = duration;
    }
};
