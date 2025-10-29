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
	Utility(const string& n, City* c) : Name(n),ct(c) {}
	void Info() { cout << Name << " " << ct->GetName() << "\n"; }
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	bool GetHasProblem() const { return HasProblem; }
	void DoEvent() { HasProblem = !HasProblem; }
};

class Building {
	string Describtion;
	int Num;
	Road* rod;
public:
	Building(const string& d, int n, Road* r) : Describtion(d),Num(n),rod(r) {}
	void Info() { cout << Describtion << " " << Num << "\n"; }
	const string& GetDescribtion() const { return Describtion; }
	void SetDescribtion(const string& n) { Describtion = n; }
	int GetNum() const { return Num; }
	void SetNum(int n) { Num = n; }
	const string& GetRoad() const { return rod->GetFulldDesc(); }
};

class Road {
	string FulldDesc;
	City* ct;
	bool HasTrafficJam = false;
	vector<unique_ptr<Building>> blds;
public:
	 Road(const string& n, City* c) : FulldDesc(n),ct(c) {}
	 void AddBuilding(const string& d, int n) {
		 blds.push_back(make_unique<Building>(d, n, this));
	 }
	 void DisplayAllBuildings() {
		 for (auto& b : blds) {
			 b->Info();
		 }
	 }
	 void Info() { cout << FulldDesc << " " << ct->GetName() << "\n"; }
	 const string& GetFulldDesc() const { return FulldDesc; }
	 void SetFulldDesc(const string& n) { FulldDesc = n; }
	 const string& GetCity() const { return ct->GetName(); }
	 bool GetHasTrafficJam() const { return HasTrafficJam; }
	 void DoEvent() { HasTrafficJam = !HasTrafficJam; }
};

class City {
	string Name;
	vector<Road> rods;
	vector<Utility> utls;
public:
	City(const string& n) : Name(n) {}
	string GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	void AddRoad(const string& n) {
		rods.push_back(Road(n, this));
	}
	void AddUtility(const string& n) {
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