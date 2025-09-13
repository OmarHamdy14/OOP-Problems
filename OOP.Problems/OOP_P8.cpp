#include "OOP_P8.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
* Problem Statement
Build a system where a person can manage items in their possession. Each item should perform a different action, 
and the person interacts with them based on type and behavior.
*/
class Fruit {
public:
	string Name;
	double Price;
	Fruit(string n,double p) : Name(n),Price(p) {}
	virtual void InfoAboutFruit() = 0;
};
class Apple : public Fruit {
public:
	Apple(string n,double p) : Fruit(n,p){}
	void InfoAboutFruit() override {
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
	}
};
class Orange : public Fruit {
	Orange(string n, double p) : Fruit(n, p) {}
	void InfoAboutFruit() override {
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
	}
};
class Date : public Fruit {
	Date(string n, double p) : Fruit(n, p) {}
	void InfoAboutFruit() override {
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
	}
};
class Person { // unique_ptr allows one owner only
public:
	string Name;
	vector<unique_ptr<Fruit>> MyFruits;
	Person(string& n) : Name(n){} // if i put & after string in constructor, it gives error !!
	void AddFruit(unique_ptr<Fruit> F) { // is this right ? ========
		MyFruits.push_back(move(F));
	}
	void PrintMyFruits() {
		for (auto& fruit : MyFruits) {
			fruit->InfoAboutFruit();
		}
	}
};