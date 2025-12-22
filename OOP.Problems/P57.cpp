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
class AggressiveDriving : public DrivingStrategy {
public:
    void Drive(Engine& engine) override {
        engine.Accelerate(20);
    }
    string Name() const override { return "Aggressive"; }
};

class DefensiveDriving : public DrivingStrategy {
public:
    void Drive(Engine& engine) override {
        engine.Accelerate(5);
    }
    string Name() const override { return "Defensive"; }
};



class WorldObject {
public:
    virtual string Interact() = 0;
};

class Road : public WorldObject {
public:
    string Interact() override {
        return "....";
    }
};

class Obstacle : public WorldObject {
public:
    string Interact() override {
        return "......";
    }
};

class Car {
    unique_ptr<ISensor> camera;
    unique_ptr<ISensor> radar;
    Engine engine;

    unique_ptr<DrivingStrategy> strategy;

public:
    Car(unique_ptr<ISensor> cam,
        unique_ptr<ISensor> rad,
        unique_ptr<DrivingStrategy> strat)
        : camera(move(cam)), radar(move(rad)), strategy(move(strat)) {
    }

    void SetDrivingStrategy(unique_ptr<DrivingStrategy> newStrategy) {
        strategy = move(newStrategy);
    }

    void ScanEnvironment() {
        cout << camera->Scan() << endl;
        cout << radar->Scan() << endl;
    }

    void Drive() {
        cout << "Driving using strategy: " << strategy->Name() << endl;
        strategy->Drive(engine);
    }

    void InteractWithWorld(WorldObject& obj) {
        cout << "Environment: " << obj.Interact() << endl;
        if (dynamic_cast<Obstacle*>(&obj)) {
            engine.Brake(10);
        }
    }
};