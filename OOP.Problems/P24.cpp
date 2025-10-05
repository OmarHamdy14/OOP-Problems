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
protected:
	string Name;
	Mode mode;
public:
	Device(string& n,Mode m) : Name(n),mode(m) {}
	virtual void Intro() = 0;
	virtual string GetName() const = 0;
	virtual void SetName(string n) = 0;
	virtual Mode GetMode() const = 0;
	virtual void SetMode(Mode n) = 0;
};
class Light : public Device {
public:
	Light(string& n, Mode m) : Device(n,m) {}
	void Intro() override {
		cout << "Light\n";
	}
	string GetName() const override { return Name; }
	void SetName(string n) override { Name = n; }
	Mode GetMode() const override { return mode; }
	void SetMode(Mode n) override { mode = n; }
};
class AC : public Device {
public:
	AC(string& n, Mode m) : Device(n, m) {}
	void Intro() override {
		cout << "AC\n";
	}
	string GetName() const override { return Name; }
	void SetName(string n) override { Name = n; }
	Mode GetMode() const override { return mode; }
	void SetMode(Mode n) override { mode = n; }
};
class Camera : public Device {
public:
	Camera(string& n, Mode m) : Device(n, m) {}
	void Intro() override {
		cout << "Camera\n";
	}
	string GetName() const override { return Name; }
	void SetName(string n) override { Name = n; }
	Mode GetMode() const override { return mode; }
	void SetMode(Mode n) override { mode = n; }
};

class Controller {
	vector<unique_ptr<Device>> devcs;
public:
	void AddDevice(unique_ptr<Device>&& d) {
		devcs.push_back(move(d));
	}
	void ChangeMode(unique_ptr<Device>& d, Mode m) {
		d->SetMode(m);
	}
	void DisplayDevices() {
		for (auto& d : devcs) {
			d->Intro();
		}
	}
};