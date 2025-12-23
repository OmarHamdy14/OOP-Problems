#include "P58.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

/*
* Problem Statement
Airline Reservation & Scheduling
Planes, Seats, Routes, Pilots.
Scheduling algorithms differ.
Reservations ensure seat locking + ticket generation.
*/

class Seat {
    string num;
    bool reserved = false;
public:
    Seat(const string& num) : num(num) {}
    string GetSeatNumber() const { return num; }
    bool IsReserved() const { return reserved; }
    bool Reserve() {
        if (!reserved) {
            reserved = true;
            return true;
        }
        return false;
    }
};

class Plane {
    string name;
    vector<Seat> seats;
public:
    Plane(const string& m, int seatCount) : name(m) {
        for (int i = 1; i <= seatCount; ++i)
            seats.emplace_back("S" + to_string(i));
    }
    string GetModel() const { return name; }
    vector<Seat>& GetSeats() { return seats; }
};


class Pilot {
    string name;
public:
    Pilot(const string& n) : name(n) {}
    string GetName() const { return name; }
};


class Route {
    string From;
    string To;
public:
    Route(const string& o, const string& d) : From(o), To(d) {}
    string GetRoute() const { return From + " -> " + To; }
};


class Reservation {
    string passengerName;
    Seat* seat;
public:
    Reservation(const string& pname, Seat* s) : passengerName(pname), seat(s) {}
    void PrintTicket() {
        cout << "Ticket for " << passengerName << "\nSeat: " << seat->GetSeatNumber() << "\n";
    }
};