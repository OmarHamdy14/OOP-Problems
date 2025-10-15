#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*  ?????????????????
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
protected:
	string Name;
public:
	Device(const string& n) : Name(n) {}
	virtual void InfoAboutDev() = 0;
	virtual const string& GetName() const = 0;
	virtual void SetName(const string& n) = 0;
};
class Printer : public Device {
public:
	Printer(const string& n) : Device(n) {}
	void InfoAboutDev() override {
		cout << "Device Name: " << Name << endl;
	}
	const string& GetName() const override { return Name; }
	void SetName(const string& n) override { Name = n; }
};
class TV : public Device {
public:
	TV(const string& n) : Device(n) {}
	void InfoAboutDev() override {
		cout << "Device Name: " << Name << endl;
	}
	const string& GetName() const override { return Name; }
	void SetName(const string& n) override { Name = n; }
};
class PC : public Device {
public:
	PC(const string& n) : Device(n) {}
	void InfoAboutDev() override {
		cout << "Device Name: " << Name << endl;
	}
	const string& GetName() const override { return Name; }
	void SetName(const string& n) override { Name = n; }
};
class DeviceManager {
	vector<shared_ptr<Device>> devices;
	const InternalPart& internalPart;
	OutsideElement outsideElement;
public:
	/* when i write "vector<shared_ptr<Device>>& devices;" the constructor gives me this error : "DeviceManager(OutsideElement& OE)"
	provide no intilization for : reference member "devices" */
	DeviceManager(const InternalPart& iE, const OutsideElement& OE) : internalPart(iE), outsideElement(OE) {}
	void AddDevice(shared_ptr<Device> d) {
		devices.push_back(d);
	}
	void StartAllDeviecs() {
		for (auto& device : devices) {
			internalPart.SendMsg(device->GetName());       // why : error appeared here when using const with constructoor parameters ?
			device->InfoAboutDev();
			outsideElement.PrintAnyThing("ssssssssssssssss");
		}
	}
};