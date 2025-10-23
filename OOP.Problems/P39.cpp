#include "P39.h"
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
Video Game Inventory
*/

class Item {
protected:
	string Name;
public:
	Item(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	virtual void Buy() const = 0;
	virtual void Equip() const = 0;
	virtual void Drop() const = 0;
};
class Gun : public Item {
public:
	Gun(const string& n) : Item(n) {}
	void Buy() const override {
		cout << "BUYING GUN ........\n";
	}
	void Equip() const override {
		cout << "EQUIPING GUN ........\n";
	}
	void Drop() const override {
		cout << "DROPING GUN ........\n";
	}
};
class MedKit : public Item {
public:
	MedKit(const string& n) : Item(n) {}
	void Buy() const override {
		cout << "BUYING MedKit ........\n";
	}
	void Equip() const override {
		cout << "EQUIPING MedKit ........\n";
	}
	void Drop() const override {
		cout << "DROPING MedKit ........\n";
	}
};
class Shovel : public Item {
public:
	Shovel(const string& n) : Item(n) {}
	void Buy() const override {
		cout << "BUYING Shovel ........\n";
	}
	void Equip() const override {
		cout << "EQUIPING Shovel ........\n";
	}
	void Drop() const override {
		cout << "DROPING Shovel ........\n";
	}
};

class Inventory {
	vector<shared_ptr<Item>> items;
public:
	void AddItem(shared_ptr<Item>& it) {
		items.push_back(it);
	}
	void DisplayAllItem() const {
		for (auto& it : items) {
			cout << it->GetName() << "\n";
		}
	}
};

class Player {
	string UserName;
	unique_ptr<Inventory> invent;
public:
	Player(const string& n) : UserName(n) {
		invent = make_unique<Inventory>();
	}
	const string& GetName() const { return UserName; }
	void SetName(const string& n) { UserName = n; }
};