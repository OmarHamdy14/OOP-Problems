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
protected:
	string Name;
	string PhoneNumber;
public:
	User(string& n,string& pn) : Name(n),PhoneNumber(pn) {}
	virtual void Info() = 0;
	virtual string GetName() const = 0;
	virtual void SetName(string& n) = 0;
	virtual string GetPhoneNumber() const = 0;
	virtual void SetPhoneNumber(string& n) = 0;
};
class Passenger : public User {
public:
	Passenger(string& n,string& pn) : User(n,pn) {}
	void Info() override { cout << "I'm Passenger\n"; }
	string GetName() const override { return Name; }
	void SetName(string& n) override { Name = n; }
	string GetPhoneNumber() const override { return PhoneNumber; }
	void SetPhoneNumber(string& n) override { PhoneNumber = n; }
};
class Driver : public User {
public:
	Driver(string& n, string& pn) : User(n, pn) {}
	void Info() override {
		cout << "I'm Driver\n";
	}
	string GetName() const override { return Name; }
	void SetName(string& n) override { Name = n; }
	string GetPhoneNumber() const override { return PhoneNumber; }
	void SetPhoneNumber(string& n) override { PhoneNumber = n; }
};

class Trip {
	string From;
	string To;
	float rating;
	shared_ptr<Driver> drv;
	shared_ptr<Passenger> psg;
public:
	Trip(string& f, string& t,float rt, shared_ptr<Driver>& drv, shared_ptr<Passenger>& psg) : From(f),To(t),rating(rt),drv(drv),psg(psg) {}
	void Info() {
		cout << From << "---------->" << To << "\n" << drv->Name << "\n" << psg->Name << "\n";
	}
	string GetFrom() const { return From; }
	void SetFrom(string& n) { From = n; }
	string GetTo() const { return To; }
	void SetTo(string& n) { To = n; }
	float Getrating() const { return rating; }
	void Setrating(float n) { rating = n; }
};

class Platform {
	vector<unique_ptr<Trip>> trps;
public:
	void AddTrip(string& f, string& t, shared_ptr<Driver>& dv, shared_ptr<Passenger>& pg) {
		trps.push_back(make_unique<Trip>(f, t, 0, dv, pg));
	}
	void RateTrip(float rt, unique_ptr<Trip>& tp) {
		tp->Setrating(rt);
	}
	void DisplayAllTrips() {
		for (auto& t : trps) {
			t->Info();
			cout << "-------------------------\n";
		}
	}
};