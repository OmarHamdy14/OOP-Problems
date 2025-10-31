#include "P43.h"
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
Airport Operations Simulator
*/

class Engine {
	string Type;
public:
	Engine(const string& t) : Type(t) {}
	const string& GetType() const { return Type; }
	void SetType(const string& t) {	Type = t; }

	void Start() const {
		cout << "Starting ...\n";
	}
	void Stop() const {
		cout << "Stopping ...\n";
	}
};


class Aircraft {
protected:
	unique_ptr<Engine> eng;
	string Type;
public:
	Aircraft(const string& t) : Type(t) {}
	void SetEngine(unique_ptr<Engine>&& en) { eng = move(en); }
	const string& GetEngineType() const { return eng->GetType(); }
	const string& GetType() const { return Type; }
	void SetType(const string& t) { Type = t; }

	virtual void Takeoff() const = 0;
	virtual void Land() const = 0;
};
class PassengerAircraft : public Aircraft {
public:
	PassengerAircraft(const string& t) : Aircraft(t) {}
	void Takeoff() const {
		cout << Type << " Takeoff\n";
	}
	void Land() const {
		cout << Type << " Land\n";
	}
};
class PrivateAircraft : public Aircraft {
public:
	PrivateAircraft(const string& t) : Aircraft(t) {}
	void Takeoff() const {
		cout << Type << " Takeoff\n";
	}
	void Land() const {
		cout << Type << " Land\n";
	}
};
class CommercialAircraft : public Aircraft {
public:
	CommercialAircraft(const string& t) : Aircraft(t) {}
	void Takeoff() const {
		cout << Type << " Takeoff\n";
	}
	void Land() const {
		cout << Type << " Land\n";
	}
};


class Runway {
	string From;
	string To;
	string ID;
	bool IsAvailable;
public:
	Runway(const string& f, const string& t, const string& id, bool isA) : From(f),To(t),ID(id),IsAvailable(isA) {}
	const string& GetFrom() const { return From; }
	void SetFrom(const string& f) { From = f; }
	const string& GetTo() const { return To; }
	void SetTo(const string& t) { To = t; }
	const string& GetID() const { return ID; }
	void SetID(const string& t) { ID = t; }
	bool IsAvailable() const { 
		if (IsAvailable) cout << "This runway is not available\n";
		else cout << "This runway is available\n";
	}
	void SetIsAvailable(bool isA) { IsAvailable = isA; }
	void Info() const {
		cout << "ID: " << ID << "\nFrom: " << From << "\nTo: " << To << "\n";
	}
};

class ControlTower {
	string Location;
	vector<unique_ptr<Runway>> runws;
public:
	ControlTower(const string& l) : Location(l) {}
	void AddRunway(unique_ptr<Runway>&& rw) {
		runws.push_back(move(rw));
	}
	void DisplayAllRunways() {
		for (auto& rw : runws) {
			rw->Info();
		}
	}
};

int main() {
	unique_ptr<Engine> eng = make_unique<Engine>("e1-3200");

	unique_ptr<Runway> rw = make_unique<Runway>("l1","l2","abc214",false);

	ControlTower ct("ll");
	ct.AddRunway(move(rw));
	ct.DisplayAllRunways();

	shared_ptr<Aircraft> psgCraft = make_shared<Aircraft>("t11-54");
	psgCraft->SetEngine(move(eng));
}