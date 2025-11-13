#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
* Problem Statement
Ride-Sharing Simulation
*/

class Passenger {
	string Name;
public: 
	Passenger(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

class Driver {
	string Name;
public:
	Driver(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

class Trip {
	string Place;
	vector<shared_ptr<Passenger>> psgs;
	vector<shared_ptr<Driver>> drvs;
public:
	Trip(const string& p) : Place(p) {}
	void AddPsg(shared_ptr<Passenger> pg) {
		psgs.push_back(pg);
	}
	void AddDrv(shared_ptr<Driver> dv) {
		drvs.push_back(dv);
	}
	const string& GetPlace() const { return Place; }
	void SetPlace(const string& n) { Place = n; }
};