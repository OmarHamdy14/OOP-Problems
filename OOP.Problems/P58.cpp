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
    string GetName() const { return name; }
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

class ISchedulingStrategy {
public:
    virtual void ScheduleFlight(Plane& plane, Pilot& pilot, Route& route) = 0;
};

class SimpleSchedule : public ISchedulingStrategy {
public:
    void ScheduleFlight(Plane& plane, Pilot& pilot, Route& route) override {
        cout << "Scheduled " << plane.GetName() << " piloted by "
            << pilot.GetName() << " on route " << route.GetRoute() << endl;
    }
};

class PrioritySchedule : public ISchedulingStrategy {
public:
    void ScheduleFlight(Plane& plane, Pilot& pilot, Route& route) override {
        cout << "Priority Schedule: " << plane.GetName() << " with "
            << pilot.GetName() << " on " << route.GetRoute() << endl;
    }
};


class Airline {
    vector<Plane> planes;
    vector<Pilot> pilots;
    vector<Route> routes;
    unique_ptr<ISchedulingStrategy> scheduler;
public:
    Airline(unique_ptr<ISchedulingStrategy> sched) : scheduler(move(sched)) {}

    void AddPlane(const Plane& p) { planes.push_back(p); }
    void AddPilot(const Pilot& p) { pilots.push_back(p); }
    void AddRoute(const Route& r) { routes.push_back(r); }

    void ScheduleFlight(int planeIdx, int pilotIdx, int routeIdx) {
        if (planeIdx >= 0 && planeIdx < planes.size() &&
            pilotIdx >= 0 && pilotIdx < pilots.size() &&
            routeIdx >= 0 && routeIdx < routes.size())
        {
            scheduler->ScheduleFlight(planes[planeIdx], pilots[pilotIdx], routes[routeIdx]);
        }
    }

    Reservation MakeReservation(const string& passenger, int planeIdx, int seatIdx) {
        if (planeIdx < 0 || planeIdx >= planes.size())
            throw runtime_error("Invalid plane");
        auto& seats = planes[planeIdx].GetSeats();
        if (seatIdx < 0 || seatIdx >= seats.size())
            throw runtime_error("Invalid seat");
        if (!seats[seatIdx].Reserve())
            throw runtime_error("Seat already reserved");
        return Reservation(passenger, &seats[seatIdx]);
    }
};