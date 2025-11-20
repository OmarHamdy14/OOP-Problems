#include "P49.h"
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
Build a smart home system where devices (Lights, Thermostat, DoorLock, Camera) are managed by a central Hub.
Include automation rules (e.g., “turn off all lights when leaving”).
*/

class Device {
protected:
	string specifications;
	bool IsOn;
public:
	Device(const string& s, bool io) : specifications(s),IsOn(io) {}
	virtual void On() = 0;
	virtual void Off() = 0;
	void Info() const {
		cout << specifications << " " << IsOn ? "On\n" : "Off\n";
	}
};
class Light : public Device {
public:
	Light(const string& s, bool io) : Device(s,io) {}
	void On() override { IsOn = true; }
	void Off() override { IsOn = false; }
};
class Thermostat : public Device {
public:
	Thermostat(const string& s, bool io) : Device(s, io) {}
	void On() override { IsOn = true; }
	void Off() override { IsOn = false; }
};
class DoorLock : public Device {
public:
	DoorLock(const string& s, bool io) : Device(s, io) {}
	void On() override { IsOn = true; }
	void Off() override { IsOn = false; }
};
class Camera : public Device {
public:
	Camera(const string& s, bool io) : Device(s, io) {}
	void On() override { IsOn = true; }
	void Off() override { IsOn = false; }
};

class AutomationRule {
public:
	virtual void Do(vector<unique_ptr<Device>>& devs) = 0;
};
class Turn_AllLights_Off : public AutomationRule {
public:
	void Do(vector<unique_ptr<Device>>& devs) override {
		for (auto& dev : devs) {
			if (dynamic_cast<Light*>(dev.get())) dev->Off();
		}
	}
};

class DeviceManager {
	vector<unique_ptr<Device>> devs;
	vector<shared_ptr<AutomationRule>> rules;
public:
	void AddDevice(unique_ptr<Device>&& dv) {
		devs.push_back(move(dv));
	}
	void TurnAllOn() {
		for (auto& dev : devs) {
			dev->On();
		}
	}
	void TurnAllOff() {
		for (auto& dev : devs) {
			dev->Off();
		}
	}

	void TurnAllLightsOff() { 
		for (auto& dev : devs) {
			if(dynamic_cast<Light*>(dev.get())) dev->Off();
		}
	}

	
	void DoRules() { // automation
		for (auto& rul : rules) {
			rul->Do(devs);
		}
	}

	void DoRules() {
		for (auto& rule : rules) {
			rule->Do(devs);
		}
};