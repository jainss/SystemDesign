#pragma once

#include <string>
#include <vector>
#include <memory>
#include "./Enums/City.h"      // Enum or class for City
#include "Screen.h"    // Assuming you will define this
#include "Show.h"      // Assuming you will define this

class Theatre {
private:
    int theatreId;
    std::string address;
    City city;

    std::vector<std::shared_ptr<Screen>> screens;
    std::vector<std::shared_ptr<Show>> shows;

public:
    Theatre() = default;

    Theatre(int id, const std::string& addr, City cityVal)
        : theatreId(id), address(addr), city(cityVal) {}

    int getTheatreId() const {
        return theatreId;
    }

    void setTheatreId(int id) {
        theatreId = id;
    }

    std::string getAddress() const {
        return address;
    }

    void setAddress(const std::string& addr) {
        address = addr;
    }

    City getCity() const {
        return city;
    }

    void setCity(City c) {
        city = c;
    }

    std::vector<std::shared_ptr<Screen>>& getScreens() {
        return screens;
    }

    void setScreens(const std::vector<std::shared_ptr<Screen>>& scr) {
        screens = scr;
    }

    std::vector<std::shared_ptr<Show>>& getShows() {
        return shows;
    }

    void setShows(const std::vector<std::shared_ptr<Show>>& shw) {
        shows = shw;
    }
};
