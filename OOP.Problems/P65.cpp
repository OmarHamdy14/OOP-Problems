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
Gym Membership System
Members subscribe to plans.
Plans differ in price and access.
Trainers assign workouts.
Attendance is tracked.
*/

class Plan {
protected:
    string name;
    double price;

public:
    Plan(string n, double p) : name(n), price(p) {}
    virtual ~Plan() = default;

    virtual bool HasPoolAccess() const = 0;
    virtual bool HasTrainerAccess() const = 0;

    string GetName() const { return name; }
    double GetPrice() const { return price; }
};

class BasicPlan : public Plan {
public:
    BasicPlan() : Plan("Basic", 30) {}

    bool HasPoolAccess() const override { return false; }
    bool HasTrainerAccess() const override { return false; }
};

class PremiumPlan : public Plan {
public:
    PremiumPlan() : Plan("Premium", 60) {}

    bool HasPoolAccess() const override { return true; }
    bool HasTrainerAccess() const override { return true; }
};


class Workout {
    string description;

public:
    Workout(string d) : description(d) {}
    string GetDescription() const { return description; }
};


class Trainer {
    string name;

public:
    Trainer(string n) : name(n) {}

    Workout AssignWorkout() const {
        return Workout("Full Body Strength Training");
    }

    string GetName() const { return name; }
};