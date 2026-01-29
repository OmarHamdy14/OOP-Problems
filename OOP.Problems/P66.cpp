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
Ride-Hailing App (Uber-like)
Riders request rides.
Drivers accept rides.
Ride price depends on distance.
Ride status updates in real time.
*/

class PriceCalculator {
public:
    virtual ~PriceCalculator() = default;
    virtual double Calculate(double distanceKm) const = 0;
};

class StandardPricing : public PriceCalculator {
public:
    double Calculate(double distanceKm) const override {
        return 5.0 + distanceKm * 2.0;
    }
};


enum class RideStatus {
    Requested,
    Accepted,
    InProgress,
    Completed
};


class Rider {
    string name;

public:
    Rider(string n) : name(n) {}
    string GetName() const { return name; }
};

class Driver {
    string name;
    bool available = true;

public:
    Driver(string n) : name(n) {}

    bool IsAvailable() const { return available; }
    void SetAvailable(bool a) { available = a; }

    string GetName() const { return name; }
};


class Ride {
    Rider& rider;
    Driver* driver = nullptr;
    double distance;
    RideStatus status = RideStatus::Requested;
    PriceCalculator& pricing;

public:
    Ride(Rider& r, double d, PriceCalculator& p)
        : rider(r), distance(d), pricing(p) {
    }

    void AssignDriver(Driver& d) {
        if (!d.IsAvailable()) {
            cout << "Ddriver not available\n";
            return;
        }
        driver = &d;
        driver->SetAvailable(false);
        status = RideStatus::Accepted;
        cout << d.GetName() << " accepted the ride\n";
    }

    void StartRide() {
        if (status == RideStatus::Accepted) {
            status = RideStatus::InProgress;
            cout << "Ride started\n";
        }
    }

    void CompleteRide() {
        if (status == RideStatus::InProgress) {
            status = RideStatus::Completed;
            driver->SetAvailable(true);
            cout << "Ride completed\n";
            cout << "Total price: $" << pricing.Calculate(distance) << endl;
        }
    }

    void ShowStatus() const {
        cout << "Ride status: ";
        switch (status) {
        case RideStatus::Requested: cout << "Requested"; break;
        case RideStatus::Accepted: cout << "Accepted"; break;
        case RideStatus::InProgress: cout << "In Progress"; break;
        case RideStatus::Completed: cout << "Completed"; break;
        }
        cout << endl;
    }
};