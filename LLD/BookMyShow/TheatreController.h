#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include "Theatre.h"
#include "Movie.h"
#include "Show.h"
#include "./Enums/City.h"

class TheatreController {
private:
    std::unordered_map<City, std::vector<std::shared_ptr<Theatre>>> cityVsTheatre;
    std::vector<std::shared_ptr<Theatre>> allTheatres;

public:
    TheatreController() = default;
    void addTheatre(const std::shared_ptr<Theatre>& theatre, City city) {
        allTheatres.push_back(theatre);
        cityVsTheatre[city].push_back(theatre);
    }

    std::unordered_map<std::shared_ptr<Theatre>, std::vector<std::shared_ptr<Show>>> 
    getAllShows(const std::shared_ptr<Movie>& movie, City city) {
        std::unordered_map<std::shared_ptr<Theatre>, std::vector<std::shared_ptr<Show>>> theatreVsShows;

        auto it = cityVsTheatre.find(city);
        if (it == cityVsTheatre.end()) return theatreVsShows;

        const auto& theatres = it->second;

        for (const auto& theatre : theatres) {
            std::vector<std::shared_ptr<Show>> matchedShows;
            for (const auto& show : theatre->getShows()) {
                if (show->getMovie()->getMovieId() == movie->getMovieId()) {
                    matchedShows.push_back(show);
                }
            }
            if (!matchedShows.empty()) {
                theatreVsShows[theatre] = matchedShows;
            }
        }

        return theatreVsShows;
    }
};
