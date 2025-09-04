#include "OOP_P15_2.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

class Segment {
protected:
    string from_, to_;
    int plannedMinutes_;
    int extraDelay_{ 0 };

public:
    Segment(string from, string to, int plannedMinutes)
        : from_(move(from)), to_(move(to)), plannedMinutes_(plannedMinutes) {}
    virtual ~Segment() = default;

    virtual string type() const = 0;
    virtual int run() {
        return plannedMinutes_ + extraDelay_;
    }
    virtual void applyDelay(int minutes) { extraDelay_ += minutes; }

    const string& from() const { return from_; }
    const string& to()   const { return to_; }
};

class BusSegment : public Segment {
public:
    BusSegment(string from, string to, int plannedMinutes)
        : Segment(move(from), move(to), plannedMinutes) {}
    string type() const override { return "Bus"; }
    int run() override {
        return Segment::run() + 5;
    }
};

class TrainSegment : public Segment {
public:
    TrainSegment(string from, string to, int plannedMinutes)
        : Segment(move(from), move(to), plannedMinutes) {}
    string type() const override { return "Train"; }
    int run() override {
        return Segment::run() + 2;
    }
};

class FlightSegment : public Segment {
public:
    FlightSegment(string from, string to, int plannedMinutes)
        : Segment(move(from), move(to), plannedMinutes) {}
    string type() const override { return "Flight"; }
    int run() override {
        return Segment::run() + 60;
    }
};

class WalkSegment : public Segment {
public:
    WalkSegment(string from, string to, int plannedMinutes)
        : Segment(move(from), move(to), plannedMinutes) {}
    string type() const override { return "Walk"; }
    int run() override {
        return Segment::run();
    }
};

class Route {
    vector<shared_ptr<Segment>> segs_;
public:
    void add(const shared_ptr<Segment>& s) { segs_.push_back(s); }
    size_t size() const { return segs_.size(); }
    shared_ptr<Segment>& operator[](size_t i) { return segs_[i]; }
    const vector<shared_ptr<Segment>>& segments() const { return segs_; }

    void replaceWith(size_t index, const vector<shared_ptr<Segment>>& repl) {
        if (index >= segs_.size()) return;
        segs_.erase(segs_.begin() + index);
        segs_.insert(segs_.begin() + index, repl.begin(), repl.end());
    }

    void removeAt(size_t index) {
        if (index < segs_.size()) segs_.erase(segs_.begin() + index);
    }
};

// ------------- Traveler -------------
class Traveler {
    string name_;
public:
    explicit Traveler(string name) : name_(move(name)) {}
    const string& name() const { return name_; }
};

// ------------- Events -------------
struct Event {
    virtual ~Event() = default;
    size_t segmentIndex; 
    explicit Event(size_t segIdx) : segmentIndex(segIdx) {}
    virtual string kind() const = 0;
};

struct DelayEvent : public Event {
    int minutes;
    DelayEvent(size_t segIdx, int mins) : Event(segIdx), minutes(mins) {}
    string kind() const override { return "Delay"; }
};

struct RerouteEvent : public Event {
    vector<shared_ptr<Segment>> replacement;
    RerouteEvent(size_t segIdx, vector<shared_ptr<Segment>> repl)
        : Event(segIdx), replacement(move(repl)) {}
    string kind() const override { return "Reroute"; }
};

struct CancelEvent : public Event {
    CancelEvent(size_t segIdx) : Event(segIdx) {}
    string kind() const override { return "Cancel"; }
};
