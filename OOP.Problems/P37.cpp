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
Smart Home Simulation
*/
class Light {
	string Type;
public:
	Light(const string& t) : Type(t) {}
	const string& GetType() const { return Type; }
	void SetType(const string& t) { Type = t; }
};

class Thermostat {
	float Power;
public:
	Thermostat(float t) : Power(t) {}
	float GetPower() const { return Power; }
	void SetPower(float t) { Power = t; }
};

class Appliance {
	float Power;
public:
	Appliance(float t) : Power(t) {}
	float GetPower() const { return Power; }
	void SetPower(float t) { Power = t; }
};

class Room {
	string Name;
	vector<Light> lghts;
	vector<Appliance> apls;
	Thermostat thmt;
public:
	Room(const string& n, const Thermostat& t) : Name(n),thmt(t) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }
	void AddLight(const Light& l) {
		lghts.push_back(l);
	}
	void AddAppliance(const Appliance& l) {
		apls.push_back(l);
	}
	const Thermostat& GetThermostat() const { return thmt; }
	void SetThermostat(const Thermostat& T) { thmt = T; }
};

class SmartHouse {
	int num;
	vector<Room> roms;
public:
	SmartHouse(int n) : num(n) {}
	void AddRoom(const Room& rm) {
		roms.push_back(rm);
	}
	void DisplayAllRooms() {
		for (auto& rm : roms) {
			cout << rm.GetName() << "\n";
		}
	}
	int GetNum() const { return num; }
	void SetNum(int t) { num = t; }
};