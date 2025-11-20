#pragma once
#include "Movie.h"
#include "./Enums/City.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class MovieController {
    private:
      std::unordered_map<City, std::vector<std::shared_ptr<Movie>>> cityVsMovies;
      std::vector<std::shared_ptr<Movie>> allMovies;

    public: 
      void addMovie(const std::shared_ptr<Movie>& movie, City city) {
        allMovies.push_back(movie);
        cityVsMovies[city].push_back(movie);
      }
      
      std::shared_ptr<Movie> getMovieByName(const std::string& movieName) const {
        for (const auto& movie : allMovies) {
            if (movie->getName() == movieName)
                return movie;
        }
        return nullptr;
      }

      std::vector<std::shared_ptr<Movie>> getMoviesByCity(City city) const {
        auto it = cityVsMovies.find(city);
        if (it != cityVsMovies.end())
            return it->second;
        return {};
      }
}