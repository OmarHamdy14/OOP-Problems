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
	void AddRoute(Route rou) {
		routes.push_back(rou);
	}
};