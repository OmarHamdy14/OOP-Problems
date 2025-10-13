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
	User(const string& n, const string& pn) : Name(n),PhoneNumber(pn) {}
	virtual void Info() = 0;
	virtual const string& GetName() const = 0;
	virtual void SetName(const string& n) = 0;
	virtual const string& GetPhoneNumber() const = 0;
	virtual void SetPhoneNumber(const string& n) = 0;
};
class Passenger : public User {
public:
	Passenger(const string& n, const string& pn) : User(n,pn) {}
	void Info() override { cout << "I'm Passenger\n"; }
	const string& GetName() const override { return Name; }
	void SetName(const string& n) override { Name = n; }
	const string& GetPhoneNumber() const override { return PhoneNumber; }
	void SetPhoneNumber(const string& n) override { PhoneNumber = n; }
};
class Driver : public User {
public:
	Driver(const string& n, const string& pn) : User(n, pn) {}
	void Info() override {
		cout << "I'm Driver\n";
	}
	const string& GetName() const override { return Name; }
	void SetName(const string& n) override { Name = n; }
	const string& GetPhoneNumber() const override { return PhoneNumber; }
	void SetPhoneNumber(const string& n) override { PhoneNumber = n; }
};

class Trip {
	string From;
	string To;
	float rating;
	shared_ptr<Driver> drv;
	shared_ptr<Passenger> psg;
public:
	Trip(const string& f, const string& t,float rt, shared_ptr<Driver>& drv, shared_ptr<Passenger>& psg) : From(f),To(t),rating(rt),drv(drv),psg(psg) {}
	void Info() {
		cout << From << "---------->" << To << "\n" << drv->GetName() << "\n" << psg->GetName() << "\n";
	}
	const string& GetFrom() const { return From; }
	void SetFrom(const string& n) { From = n; }
	const string& GetTo() const { return To; }
	void SetTo(const string& n) { To = n; }
	float Getrating() const { return rating; }
	void Setrating(float n) { rating = n; }
};

class Platform {
	vector<unique_ptr<Trip>> trps;
public:
	void AddTrip(const string& f, const string& t, shared_ptr<Driver>& dv, shared_ptr<Passenger>& pg) {
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