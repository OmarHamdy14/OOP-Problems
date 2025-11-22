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
Emergency Response Simulator
*/

class Unit {
protected:
	string describtion;
public:
	Unit(const string& n) : describtion(n) {}
	const string& Getdescribtion() const { return describtion; }
	void Setdescribtion(const string& t) { describtion = t; }

	virtual void Work() const = 0;
};
class Police : public Unit {
public:
	Police(const string& n) : Unit(n) {}
	void Work() const {
		cout << "Police ...... work\n";
	}
};
class Fire : public Unit {
public:
	Fire(const string& n) : Unit(n) {}
	void Work() const {
		cout << "Fire ...... work\n";
	}
};
class Ambulance : public Unit {
public:
	Ambulance(const string& n) : Unit(n) {}
	void Work() const {
		cout << "Ambulance ...... work\n";
	}
};

class Incident {
	string describtion;
public:
	Incident(const string& n) : describtion(n) {}
	const string& Getdescribtion() const { return describtion; }
	void Setdescribtion(const string& t) { describtion = t; }
};

class Dispatcher {
	string Name;
public:
	Dispatcher(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }
	void SendPolice(Incident& incd, shared_ptr<Police>& plc) {
		cout << "Sending Police ..........\n";
	}
	void SendFire(Incident& incd, shared_ptr<Fire>& f) {
		cout << "Sending Fire ..........\n";
	}
	void SendAmbulance(Incident& incd, shared_ptr<Fire>& f) {
		cout << "Sending Ambulance ..........\n";
	}
};

int main() {
	shared_ptr<Police> police = make_shared<Police>();
	shared_ptr<Fire> fire = make_shared<Fire>();

	Incident inc("");

	Dispatcher disp("ddd");
	disp.SendFire(inc, fire);
}