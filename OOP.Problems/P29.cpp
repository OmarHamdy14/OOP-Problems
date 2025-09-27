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
public:
	string from;
	string to;
	bool IsTaken;
	RunWay(string& f, string& t,bool i) : from(f),to(t),IsTaken(i) {}
};
class Plane {
public:
	
};
class ATC {
public:
	vector<unique_ptr<RunWay>> rws;
	void AddRunWay(string& f,string& t) {
		rws.push_back(make_unique<RunWay>(f,t,false));
	}
	void RequestTakeOff(Plane& p, unique_ptr<RunWay>& rw) {
		rw->IsTaken = false;
	}
	void RequestLanding(Plane& p, unique_ptr<RunWay>& rw) {
		if (rw->IsTaken == true) {
			cout << "No\n";
			return;
		}
		rw->IsTaken = true;
		cout << "done\n";
	}
};