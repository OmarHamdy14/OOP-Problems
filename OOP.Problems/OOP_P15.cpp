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
	string Name;
public:
	Event(string& n) : Name(n) {}
	string GetName() const { return Name; }
	void SetName(string& s) { Name = s; }
};

class Segment {
protected:
	string Name;
	double Price;
	vector<shared_ptr<Event>> Events;
public:
	Segment(string& n,double p) : Name(n),Price(p) {}
	virtual void Info() = 0;
	virtual void AddEvent(shared_ptr<Event>& eve) = 0;
	virtual string GetName() const = 0;
	virtual void SetName(string& s) = 0;
	virtual double GetPrice() const = 0;
	virtual void SetPrice(double p) = 0;
};
class BusSegment : Segment {
public:
	BusSegment(string& n, double p) : Segment(n,p) {}
	void Info() {
		cout << "Bussss" << endl;
	}
	void AddEvent(shared_ptr<Event>& eve) {
		Events.push_back(eve);
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
	double GetPrice() const override { return Price; }
	void SetPrice(double p) override { Price = p; }
};
class WalkSegment : Segment {
public:
	WalkSegment(string& n, double p) : Segment(n, p) {}
	void Info() {
		cout << "Walkkkkk" << endl;
	}
	void AddEvent(shared_ptr<Event>& eve) {
		Events.push_back(eve);
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
	double GetPrice() const override { return Price; }
	void SetPrice(double p) override { Price = p; }
};
class TrainSegment : Segment {
public:
	TrainSegment(string& n, double p) : Segment(n, p) {}
	void Info() {
		cout << "Trainnnn" << endl;
	}
	void AddEvent(shared_ptr<Event>& eve) {
		Events.push_back(eve);
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
	double GetPrice() const override { return Price; }
	void SetPrice(double p) override { Price = p; }
};

class Route {
	string Name;
public:
	Route(string& n) : Name(n) {}
	vector<unique_ptr<Segment>> Segments;
	void AddSegment(unique_ptr<Segment>&& seg) {
		Segments.push_back(move(seg));
	}
	string GetName() const { return Name; }
	void SetName(string& s) { Name = s; }
};

class Traveler {
	string Name;
	vector<Route> routes;
public:
	Traveler(string& n) : Name(n) {}
	void AddRoute(Route& rou) {
		routes.push_back(rou);
	}
	string GetName() const { return Name; }
	void SetName(string& s) { Name = s; }
};
// what is better using vector<Route> routes or vector<unique_ptr<Route>> routes ?? =======

class SystemManager {
public:
	void CreateRoute(Traveler& trav,Route& rou) {
		trav.AddRoute(rou);
	}
	void AddBusSegmentToRoute(unique_ptr<Segment>&& seg, Route& rou) {
		rou.AddSegment(move(seg));
	}
	void AddEventToSegment(shared_ptr<Event> eve, unique_ptr<Segment>&& seg) {
		seg->AddEvent(eve);
	}
};
int main() {

}







/*
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



class RouteManager {
public:
	struct Result {
		int totalMinutes{ 0 };
		vector<string> log;
	};

	Result travel(Traveler& t, Route& route, vector<shared_ptr<Event>> events) {
		Result res;
		res.log.push_back("Traveler " + t.name() + " begins journey.");

		// We'll iterate with index i; since reroute/cancel can change route,
		// we re-check events each iteration with current i.
		size_t i = 0;
		while (i < route.size()) {
			// Handle any events targeting this index (there might be multiple)
			// We consume events as we apply them.
			bool modified = true;
			while (modified) {
				modified = false;
				for (auto it = events.begin(); it != events.end(); ) {
					if ((*it)->segmentIndex == i) {
						auto& e = *it;
						if (auto* d = dynamic_cast<DelayEvent*>(e.get())) {
							route[i]->applyDelay(d->minutes);
							res.log.push_back("Event@seg " + to_string(i) + " [Delay +" + to_string(d->minutes) + " min] on " + route[i]->type());
							it = events.erase(it);
							modified = true;
							continue;
						}
						if (auto* r = dynamic_cast<RerouteEvent*>(e.get())) {
							string oldType = route[i]->type();
							route.replaceWith(i, r->replacement);
							res.log.push_back("Event@seg " + to_string(i) + " [Reroute] replaced " + oldType + " with "
								+ to_string(r->replacement.size()) + " segment(s).");
							it = events.erase(it);
							modified = true;
							continue; // re-check same index after replacement
						}
						if (dynamic_cast<CancelEvent*>(e.get())) {
							string oldType = route[i]->type();
							route.removeAt(i);
							res.log.push_back("Event@seg " + to_string(i) + " [Cancel] removed " + oldType + " segment.");
							it = events.erase(it);
							modified = true;
							// Don't increment i; we now have a new seg at i (or none)
							continue;
						}
					}
					else {
						++it;
					}
				}
			}

			if (i >= route.size()) break; // might become empty after events

			auto& seg = route[i];
			res.log.push_back("Starting seg " + to_string(i) + ": " + seg->type()
				+ " (" + seg->from() + " -> " + seg->to() + ")");
			int minutes = seg->run();
			res.totalMinutes += minutes;
			res.log.push_back("Finished seg " + to_string(i) + ": +" + to_string(minutes) + " min");
			++i;
		}

		res.log.push_back("Journey complete. Total time: " + to_string(res.totalMinutes) + " min.");
		return res;
	}
};

*/