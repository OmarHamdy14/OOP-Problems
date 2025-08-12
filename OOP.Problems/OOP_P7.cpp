#include "OOP_P7.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
* Problem Statement
Design a complete structure combining general and specific behavior, internal parts managed directly, and outside elements passed in. 
Have each part interact meaningfully and demonstrate the whole system working together.
*/
class OutsideElement {
public:
	void PrintAnyThing(string msg) {
		cout << "Message from outside element: " << msg << endl;
	}
};
class InternalPart {
public:
	void SendMsg(string DName) {
		cout << "Message from Internal Part: Preparation for " << DName << "is done ........" << endl;
	}
};
class Device {
public:
	string Name;
	Device(string n) : Name(n) {}
	virtual void InfoAboutDev() = 0;
};
class Printer : public Device {
public:
	Printer(string n) : Device(n) {}
	void InfoAboutDev() {
		cout << "Device Name: " << Name << endl;
	}
};
class TV : public Device {
public:
	TV(string n) : Device(n) {}
	void InfoAboutDev() {
		cout << "Device Name: " << Name << endl;
	}
};
class PC : public Device {
public:
	PC(string n) : Device(n) {}
	void InfoAboutDev() {
		cout << "Device Name: " << Name << endl;
	}
};
class DeviceManager {
public:
	vector<shared_ptr<Device>>& devices;
	InternalPart internalPart;
	OutsideElement& outsideElement;
	DeviceManager(vector<shared_ptr<Device>>& d, OutsideElement& OE) : devices(d),outsideElement(OE) {}
	void AddDevice(shared_ptr<Device> d) {
		devices.push_back(d);
	}
	void StartAllDeviecs() {
		for (auto& device : devices) {
			internalPart.SendMsg(device->Name);
			device->InfoAboutDev();
			outsideElement.PrintAnyThing("ssssssssssssssss");
		}
	}
};