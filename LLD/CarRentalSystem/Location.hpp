#pragma once
#include <string>
using namespace std;

class Location {
    public:
      string address;
      int pincode;
      string city, state, country;
      Location(string address, int pincode, string city, string state, string country): address(address), pincode(pincode), city(city), state(state), country(country) {}
      string getAddress() { return address; }
      int getPincode() { return pincode; }
      string getCity() { return city; }
      string getState() { return state; }
      string getCountry() { return country; }
};