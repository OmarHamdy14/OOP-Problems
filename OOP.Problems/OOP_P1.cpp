/*
* Problem Statement:
Create a general class with common data and behavior. Then, create several more specific classes based on it, 
each with different outputs for a shared method.
*/
#include "OOP_P1.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Base {
public:
	int Score;
	Base(int s) {
		Score = s;
	}
	virtual void display() = 0;
};
class Derived1 : Base {
	Derived1(int s) : Base(s) {

	}
	void display() {
		cout << "I'm Derived 1, my score is " << Score << endl;
	}
};
class Derived2 : Base { 
	Derived2(int s) : Base(s) {

	}
	void display() {
		cout << "I'm Derived 3, my score is " << Score << endl;
	}
};
class Derived3 : Base {
	Derived3(int s) : Base(s) {

	}
	void display() {
		cout << "I'm Derived 3, my score is " << Score << endl;
	}
};
