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
    Engine(string t) : type(t) {}
    string GetType() const { return type; }
    void Start() { cout << "starting......... \n"; }
};


class CrewMember {
    string name;
    string role;
public:
    CrewMember(string n, string r) : name(n), role(r) {}
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