#include "P25.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Ride-Sharing Platform
- Drivers and passengers are matched.
- Track trips, payments, and ratings.
*/
class User {
public:
	string Name;
	string PhoneNumber;
	User(string& n,string& pn) : Name(n),PhoneNumber(pn) {}
	virtual void Info() = 0;
};
class Passenger : public User {
public:
	Passenger(string& n,string& pn) : User(n,pn) {}
	void Info() override {
		cout << "I'm Passenger\n";
	}
};
class Driver : public User {
public:
	Driver(string& n, string& pn) : User(n, pn) {}
	void Info() override {
		cout << "I'm Driver\n";
	}
};

class Trip {
public:
	string From;
	string To;
	float rating;
	shared_ptr<Driver> drv;
	shared_ptr<Passenger> psg;
	Trip(string& f, string& t,float rt, shared_ptr<Driver>& drv, shared_ptr<Passenger>& psg) : From(f),To(t),rating(rt),drv(drv),psg(psg) {}
	void Info() {
		cout << From << "---------->" << To << "\n" << drv->Name << "\n" << psg->Name << "\n";
	}
};

class Platform {
public:
	vector<unique_ptr<Trip>> trps;
	void AddTrip(string& f, string& t, shared_ptr<Driver>& dv, shared_ptr<Passenger>& pg) {
		trps.push_back(make_unique<Trip>(f, t, 0, dv, pg));
	}
	void RateTrip(float rt, unique_ptr<Trip>& tp) {
		tp->rating = rt;
	}
	void DisplayAllTrips() {
		for (auto& t : trps) {
			t->Info();
			cout << "-------------------------\n";
		}
	}
};