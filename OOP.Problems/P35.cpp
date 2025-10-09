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
class Utility {
	string Name;
	City* ct;
	bool HasProblem = false;	
public:
	Utility(string& n, City* c) : Name(n),ct(c) {}
	void Info() { cout << Name << " " << ct->GetName() << "\n"; }
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
	bool GetHasProblem() const { return HasProblem; }
	void DoEvent() { HasProblem = !HasProblem; }
};

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
	bool HasTrafficJam = false;
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
	 bool GetHasTrafficJam() const { return HasTrafficJam; }
	 void DoEvent() { HasTrafficJam = !HasTrafficJam; }
};

class City {
	string Name;
	vector<Road> rods;
	vector<Utility> utls;
public:
	City(string& n) : Name(n) {}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
	void AddRoad(string& n) {
		rods.push_back(Road(n, this));
	}
	void AddUtility(string& n) {
		utls.push_back(Utility(n, this));
	}
	void DisplayAllRoads() {
		for (auto& r : rods) {
			r.Info();
		}
	}
	void Event() {
		int rndm = rand() % 3;
		if (rndm == 0 && !rods.empty()) {
			int idx = rand() % rods.size();
			rods[idx].DoEvent();
			cout << "Something happen !!\n" << rods[idx].GetHasTrafficJam() ? "there is a traffic jam\n" : "everything is good now\n";
		}
		else if (rndm == 1 && !utls.empty()) {
			int idx = rand() % utls.size();
			utls[idx].DoEvent();
			cout << "Something happen !!\n" << utls[idx].GetHasProblem() ? "there is a problem\n" : "everything is good now\n";
		}
		else {
			cout << "No problem ... everything is good in the city\n";
		}
	}
};