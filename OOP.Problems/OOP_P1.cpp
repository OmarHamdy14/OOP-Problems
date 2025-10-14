/*
* Problem Statement:
Create a general class with common data and behavior. Then, create several more specific classes based on it, 
each with different outputs for a shared method.
*/
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Base {
protected:	
	int Score;
public:
	Base(int s) {
		Score = s;
	}
	virtual void display() = 0;
	virtual int GetBase() const = 0;
	virtual void SetBase(int s) = 0;
};
class Derived1 : public Base {
public:
	Derived1(int s) : Base(s) {}
	void display() override {
		cout << "I'm Derived 1, my score is " << Score << endl;
	}
	int GetBase() const override {
		return Score;
	}
	void SetBase(int s) override {
		Score = s;
	}
};
class Derived2 : public Base {
public:
	Derived2(int s) : Base(s) {}
	void display() override {
		cout << "I'm Derived 3, my score is " << Score << endl;
	}
	int GetBase() const override {
		return Score;
	}
	void SetBase(int s) override {
		Score = s;
	}
};
class Derived3 : public Base {
public:
	Derived3(int s) : Base(s) {}
	void display() override {
		cout << "I'm Derived 3, my score is " << Score << endl;
	}
	int GetBase() const override {
		return Score;
	}
	void SetBase(int s) override {
		Score = s;
	}
};
