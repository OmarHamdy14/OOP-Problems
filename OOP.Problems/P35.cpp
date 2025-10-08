#include "P35.h"
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
City Simulation (Mini SimCity)
- Roads, buildings, and utilities interact.
- Events like power outage or traffic jam affect city life.
*/
class Building {
	string Describtion;
	int Num;
	Road* rod;
public:
	Building(string& d, int n, Road* r) : Describtion(d),Num(n),rod(r) {}
	void Info() { cout << Describtion << " " << Num << "\n"; }
	string GetDescribtion() const { return Describtion; }
	void SetDescribtion(string& n) { Describtion = n; }
	int GetNum() const { return Num; }
	void SetNum(int n) { Num = n; }
	string GetRoad() const { return rod->GetFulldDesc(); }
};

class Road {
	string FulldDesc;
	City* ct;
	vector<unique_ptr<Building>> blds;
public:
	 Road(string& n, City* c) : FulldDesc(n),ct(c) {}
	 void AddBuilding(string& d, int n) {
		 blds.push_back(make_unique<Building>(d, n, this));
	 }
	 void DisplayAllBuildings() {
		 for (auto& b : blds) {
			 b->Info();
		 }
	 }
	 void Info() { cout << FulldDesc << " " << ct->GetName() << "\n"; }
	 string GetFulldDesc() const { return FulldDesc; }
	 void SetFulldDesc(string& n) { FulldDesc = n; }
	 string GetCity() const { return ct->GetName(); }
};

class City {
	string Name;
	vector<Road> rods;
public:
	City(string& n) : Name(n) {}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
	void AddRoad(string& n) {
		rods.push_back(Road(n, this));
	}
	void DisplayAllRoads() {
		for (auto& r : rods) {
			r.Info();
		}
	}
};