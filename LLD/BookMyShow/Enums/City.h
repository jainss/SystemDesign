#pragma once
#include <string>

enum class City {
    DELHI,
    MUMBAI,
    BANGALORE,
    CHENNAI,
    KOLKATA
};

inline std::string cityToString(City city) {
    switch (city) {
        case City::DELHI: return "Delhi";
        case City::MUMBAI: return "Mumbai";
        case City::BANGALORE: return "Bangalore";
        case City::CHENNAI: return "Chennai";
        case City::KOLKATA: return "Kolkata";
        default: return "Unknown";
    }
}
