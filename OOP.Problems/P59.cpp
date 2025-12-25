#include "P59.h"
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
Smart Traffic System
Sensors, Cameras, TrafficLights.
AI controls flow based on rules.
Emergency vehicles override signals.
*/

class TrafficObserver {
public:
    virtual void OnTrafficUpdate(const string& data) = 0;
};


class TrafficTool {
protected:
    vector<TrafficObserver*> observers;
public:
    void Attach(TrafficObserver* obs) {
        observers.push_back(obs);
    }
    void Notify(const string& data) {
        for (auto* o : observers)
            o->OnTrafficUpdate(data);
    }
};


class Sensor : public TrafficTool {
protected:
    string id;
public:
    Sensor(const string& i) : id(i) {}
    virtual void Detect() = 0;
};

class Camera : public Sensor {
public:
    Camera(const string& i) : Sensor(i) {}
    void Detect() override {
        Notify("Camera " + id + ": ..........");
    }
};

class RoadSensor : public Sensor {
public:
    RoadSensor(const string& i) : Sensor(i) {}
    void Detect() override {
        Notify("RoadSensor " + id + ": ........");
    }
};


enum class LightState { RED, GREEN, YELLOW };

class TrafficLight {
    LightState state = LightState::RED;
public:
    void SetState(LightState s) {
        state = s;
        cout << "Traffic Light -> "
            << (state == LightState::GREEN ? "GREEN" :
                state == LightState::YELLOW ? "YELLOW" : "RED")
            << endl;
    }
};