#include "OOP_P9.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
* Problem Statement
Create a structure where a central service coordinates operations between several independent units. 
Each unit has a distinct role and different ways of performing tasks, but they all contribute to a common goal.
*/

// *** num + num * num / num ==> num (Add class) num (Multiply class) num (Division class) num
class Common {
public:
	virtual void work() = 0;
};
class UnitOne : public Common {
public:
	void work () override {
		cout << "Hello from UnitOne" << endl;
	}
};
class UnitTwo : public Common {
public:
	void work() override {
		cout << "Hello from UnitTwo" << endl;
	}
};
class CentralService {
public:
	vector<shared_ptr<Common>> Commons;
	void AddOperation(shared_ptr<Common> u) {
		Commons.push_back(u);
	}
	void AllWork() {
		for (auto& c : Commons) {
			c->work();
		}
	}
};
int main() {


}