#include "P40.h"
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
Restaurant Kitchen System
*/

class Appliance {
protected:
	string Name;
public:
	Appliance(const string& n) : Name(n){}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	virtual void Work() const = 0;
};
class Oven : public Appliance {
public:
	Oven(const string& n) : Appliance(n) {}
	void Work() const override {
		cout << "Oven Work\n";
	}
};
class Fryer : public Appliance {
public:
	Fryer(const string& n) : Appliance(n) {}
	void Work() const override {
		cout << "Oven Work\n";
	}
};

class Dish {
	string Name;
	vector<shared_ptr<Appliance>> tools;
public:
	Dish(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	void AddTool(shared_ptr<Appliance>& t) {
		tools.push_back(t);
	}
};

class Chef {
	string Name;
	vector<unique_ptr<Dish>> dishes;
public:
	Chef(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	void AddDish(unique_ptr<Dish>&& dsh) {
		dishes.push_back(move(dsh));
	}
};