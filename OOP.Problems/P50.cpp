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
Space Exploration Simulation Spaceships have Engines, Crews, and Missions. 
Different ship types specialize in exploration, transport, or research. 
Mission control coordinates all ships and resources.
*/

class Engine {
    string type;
public:
    Engine(const string& t) : type(t) {}
    string GetType() const { return type; }
    void Start() { cout << "starting......... \n"; }
};


class CrewMember {
    string name;
    string role;
public:
    CrewMember(const string& n, string r) : name(n), role(r) {}
    void Info() const { cout << role << ": " << name << "\n"; }
};


class Mission {
public:
    virtual void Execute() = 0;
};

class ExplorationMission : public Mission {
public:
    void Execute() override { cout << "exploration mission...\n"; }
};

class TransportMission : public Mission {
public:
    void Execute() override { cout << "transport mission...\n"; }
};

class ResearchMission : public Mission {
public:
    void Execute() override { cout << "research mission...\n"; }
};

class Spaceship {
protected:
    string name;
    shared_ptr<Engine> engine;
    vector<CrewMember> crew;
    shared_ptr<Mission> mission;

public:
    Spaceship(const string& n, shared_ptr<Engine> e, shared_ptr<Mission> m)
        : name(n), engine(e), mission(m) {}

    void AddCrewMember(const CrewMember& cm) { crew.push_back(cm); }

    virtual void Launch() {
        cout << "Spaceship " << name << " launching........\n";
        engine->Start();
        mission->Execute();
    }

    void CrewInfo() const {
        for (auto& c : crew) c.Info();
    }
};

class ExplorerShip : public Spaceship {
public:
    ExplorerShip(const string& n, shared_ptr<Engine> e, shared_ptr<Mission> m)
        : Spaceship(n, e, m) {}
    void Launch() override {
        cout << "Explorer ship launching......\n";
    }
};

class TransportShip : public Spaceship {
public:
    TransportShip(const string& n, shared_ptr<Engine> e, shared_ptr<Mission> m)
        : Spaceship(n, e, m) {}
    void Launch() override {
        cout << "Transport ship launching......\n";
    }
};

class ResearchShip : public Spaceship {
public:
    ResearchShip(const string& n, shared_ptr<Engine> e, shared_ptr<Mission> m)
        : Spaceship(n, e, m) {}
    void Launch() override {
        cout << "Research ship launching......\n";
     }
};


class MissionControl {
    vector<shared_ptr<Spaceship>> fleet;
public:
    void AddShip(shared_ptr<Spaceship> ship) { fleet.push_back(ship); }
    void LaunchAll() {
        for (auto& ship : fleet) {
            ship->Launch();
            cout << endl;
        }
    }
};