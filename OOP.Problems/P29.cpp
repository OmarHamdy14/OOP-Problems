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
	RunWay(const string& f, const string& t,bool i) : from(f),to(t),IsTaken(i) {}
	const string& GetFrom() const { return from; }
	void SetFrom(const string& n) { from = n; }
	const string& GetTo() const { return to; }
	void SetTo(const string& n) { to = n; }
	bool GetIsTaken() const { return IsTaken; }
	void SetIsTaken(bool n) { IsTaken = n; }
};
class Plane {
public:
	
};
class ATC {
	vector<unique_ptr<RunWay>> rws;
public:
	void AddRunWay(const string& f, const string& t) {
		rws.push_back(make_unique<RunWay>(f,t,false));
	}
	void RequestTakeOff(const Plane& p, unique_ptr<RunWay>& rw) {
		rw->SetIsTaken(false);
	}
	void RequestLanding(const Plane& p, unique_ptr<RunWay>& rw) {
		if (rw->GetIsTaken() == true) {
			cout << "No\n";
			return;
		}
		rw->SetIsTaken(true);
		cout << "done\n";
	}
};