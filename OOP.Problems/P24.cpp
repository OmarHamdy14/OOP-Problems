#include "P24.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Smart Home Automation
- Devices (light, AC, camera) can be controlled.
- Define modes (night mode, vacation mode).
*/

enum Mode {
	night,
	vacation
};
class Device {
public:
	string Name;
	Mode mode;
	Device(string& n,Mode m) : Name(n),mode(m) {}
	virtual void Intro() = 0;
};
class Light : public Device {
public:
	Light(string& n, Mode m) : Device(n,m) {}
	void Intro() override {
		cout << "Light\n";
	}
};
class AC : public Device {
public:
	AC(string& n, Mode m) : Device(n, m) {}
	void Intro() override {
		cout << "AC\n";
	}
};
class Camera : public Device {
public:
	Camera(string& n, Mode m) : Device(n, m) {}
	void Intro() override {
		cout << "Camera\n";
	}
};

class Controller {
public:
	vector<unique_ptr<Device>> devcs;
	void AddDevice(unique_ptr<Device>&& d) {
		devcs.push_back(move(d));
	}
	void ChangeMode(unique_ptr<Device>& d, Mode m) {
		d->mode = m;
	}
	void DisplayDevices() {
		for (auto& d : devcs) {
			d->Intro();
		}
	}
};