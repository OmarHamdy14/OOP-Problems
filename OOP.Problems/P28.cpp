#include "P28.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Zoo Simulation
- Different animals with behaviors (eat, sleep, makeSound).
- Zookeeper feeds and manages animals.
*/
class Animal {
public:
	string Name;
	Animal(string& s) : Name(s) {}
	virtual void Eat() = 0;
	virtual void Sleep() = 0;
	virtual void makeSound() = 0;
};
class Lion : public Animal {
public:
	Lion(string& n) : Animal(n) {}
	void Eat() { cout << "Lion Eating\n"; }
	void Sleep() { cout << "Lion Sleeping\n"; }
	void MakeSound() { cout << "Lion Sound\n"; }
};
class Tiger : public Animal {
public:
	Tiger(string& n) : Animal(n) {}
	void Eat() { cout << "Tiger Eating\n"; }
	void Sleep() { cout << "Tiger Sleeping\n"; }
	void MakeSound() { cout << "Tiger Sound\n"; }
};
class Giraffe : public Animal {
public:
	Giraffe(string& n) : Animal(n) {}
	void Eat() { cout << "Giraffe Eating\n"; }
	void Sleep() { cout << "Giraffe Sleeping\n"; }
	void MakeSound() { cout << "Giraffe Sound\n"; }
};

class Zoo {
public:
	vector<unique_ptr<Animal>> Anmls;
	void AddAnimal(unique_ptr<Animal>&& an) {
		Anmls.push_back(move(an));
	}
	void RemoveAnimal(unique_ptr<Animal>& anm) {
		for (auto it = Anmls.begin(); it != Anmls.end(); ++it) {
			if (it->get()->Name == anm->Name) { Anmls.erase(it); break; }
		}
		cout << "This element is not found !!!\n";
	}
	void FeedAnimals() {
		for (auto& an : Anmls) {
			an->Eat();
		}
		cout << "Feeding animals is done\n";
	}
};