#include "P57.h"
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
Autonomous Car Simulation
Car composed of: Camera, Radar, Engine, DrivingAI.
Different driving algorithms (Aggressive, Defensive).
World objects interact (roads, obstacles).
*/


class ISensor {
public:
    virtual string Scan() = 0;
};

class Camera : public ISensor {
public:
    string Scan() override {
        return "Camera: Detecting lane markings and vehicles.";
    }
};

class Radar : public ISensor {
public:
    string Scan() override {
        return "Radar: Measuring distance to obstacles.";
    }
};


class Engine {
    int speed = 0;
public:
    void Accelerate(int delta) {
        speed += delta;
        cout << "Engine: Speed increased to " << speed << endl;
    }
    void Brake(int delta) {
        speed -= delta;
        if (speed < 0) speed = 0;
        cout << "Engine: Speed decreased to " << speed << endl;
    }
    int GetSpeed() const { return speed; }
};


class DrivingStrategy {
public:
    virtual void Drive(Engine& engine) = 0;
    virtual string Name() const = 0;
};