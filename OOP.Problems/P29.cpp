#include "P29.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Air Traffic Control
- Planes request takeoff/landing.
- ATC assigns runways and manages conflicts.
*/
class RunWay {
	string from;
	string to;
	bool IsTaken;
public:
	RunWay(string& f, string& t,bool i) : from(f),to(t),IsTaken(i) {}
	string GetFrom() const { return from; }
	void SetFrom(string n) { from = n; }
	string GetTo() const { return to; }
	void SetTo(string n) { to = n; }
	bool GetIsTaken() const { return IsTaken; }
	void SetIsTaken(bool n) { IsTaken = n; }
};
class Plane {
public:
	
};
class ATC {
	vector<unique_ptr<RunWay>> rws;
public:
	void AddRunWay(string& f,string& t) {
		rws.push_back(make_unique<RunWay>(f,t,false));
	}
	void RequestTakeOff(Plane& p, unique_ptr<RunWay>& rw) {
		rw->SetIsTaken(false);
	}
	void RequestLanding(Plane& p, unique_ptr<RunWay>& rw) {
		if (rw->GetIsTaken() == true) {
			cout << "No\n";
			return;
		}
		rw->SetIsTaken(true);
		cout << "done\n";
	}
};