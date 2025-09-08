#include "OOP_P15.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;
/*
* Problem Statement
Design a transportation network where travelers can plan routes, switch modes, and encounter events (e.g., delay, reroute). 
Each segment should have unique behaviors and properties, and the system must manage transitions seamlessly.
*/

class Segment {
protected:
	string from_, to_;
	int plannedMinutes_;
	int extraDelay_{ 0 }; // applied by events

public:
	Segment(string from, string to, int plannedMinutes)
		: from_(move(from)), to_(move(to)), plannedMinutes_(plannedMinutes) {}
	virtual ~Segment() = default;

	virtual string type() const = 0;
	virtual int run() {
		// Default: planned + any event-based delays
		return plannedMinutes_ + extraDelay_;
	}
	virtual void applyDelay(int minutes) { extraDelay_ += minutes; }

	const string& from() const { return from_; }
	const string& to()   const { return to_; }
};

class BusSegment : public Segment {
public:
	// plannedMinutes includes timetable + nominal traffic
	BusSegment(string from, string to, int plannedMinutes)
		: Segment(move(from), move(to), plannedMinutes) {}
	string type() const override { return "Bus"; }
	int run() override {
		// Bus could have a small handling overhead (boarding, stops)
		return Segment::run() + 5;
	}
};

class TrainSegment : public Segment {
public:
	TrainSegment(string from, string to, int plannedMinutes)
		: Segment(move(from), move(to), plannedMinutes) {}
	string type() const override { return "Train"; }
	int run() override {
		// Trains are efficient: small overhead (platform transition)
		return Segment::run() + 2;
	}
};

class FlightSegment : public Segment {
public:
	FlightSegment(string from, string to, int plannedMinutes)
		: Segment(move(from), move(to), plannedMinutes) {}
	string type() const override { return "Flight"; }
	int run() override {
		// Flights add check-in + security/boarding overhead
		return Segment::run() + 60; // simplified fixed overhead
	}
};

class WalkSegment : public Segment {
public:
	WalkSegment(string from, string to, int plannedMinutes)
		: Segment(move(from), move(to), plannedMinutes) {}
	string type() const override { return "Walk"; }
	int run() override {
		// Walking has no extra overhead
		return Segment::run();
	}
};

class Event {
public:
	string Name;
	Event(string n) : Name(n) {}
};
class Segment {
public:
	string Name;
	double Price;
	vector<shared_ptr<Event>> Events;
	Segment(string n,double p) : Name(n),Price(p) {}
	virtual void Info() = 0;
	virtual void AddEvent(shared_ptr<Event> eve) = 0;
};
class BusSegment : Segment {
public:
	BusSegment(string n, double p) : Segment(n,p) {}
	void Info() {
		cout << "Bussss" << endl;
	}
	void AddEvent(shared_ptr<Event> eve) {
		Events.push_back(eve);
	}
};
class WalkSegment : Segment {
public:
	WalkSegment(string n, double p) : Segment(n, p) {}
	void Info() {
		cout << "Walkkkkk" << endl;
	}
	void AddEvent(shared_ptr<Event> eve) {
		Events.push_back(eve);
	}
};
class TrainSegment : Segment {
public:
	TrainSegment(string n, double p) : Segment(n, p) {}
	void Info() {
		cout << "Trainnnn" << endl;
	}
	void AddEvent(shared_ptr<Event> eve) {
		Events.push_back(eve);
	}
};
class Route {
public:
	string Name;
	Route(string n) : Name(n) {}
	vector<unique_ptr<Segment>> Segments;
	void AddSegment(unique_ptr<Segment> seg) {
		Segments.push_back(seg);
	}
};
class Traveler {
public:
	string Name;
	vector<Route> routes;
	Traveler(string n) : Name(n) {}
	void AddRoute(Route& rou) {
		routes.push_back(rou);
	}
};
class SystemManager {
public:
	void CreateRoute(Traveler& trav,Route& rou) {
		trav.AddRoute(rou);
	}
	void AddBusSegmentToRoute(string n,double p, Route& rou) {
		rou.AddSegment(make_unique<Segment>(n,p));
	}
	void AddEventToSegment(shared_ptr<Event> eve, unique_ptr<Segment> seg) {
		seg->AddEvent(eve);
	}
};
int main() {

}