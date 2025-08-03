#include "OOP_P4.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
* Problem Statement
Build a system where several related classes behave differently but share a common interface. 
Demonstrate their behavior through a loop that calls the same method on each.
*/

class Counter {
public:
	virtual void Count(int st) = 0;
};
class MultiplyBy10 : public Counter {
public:
	void Count(int st) {
		for (int i = 0; i <= 10 * st; i += 2) {
			cout << i << " ";
		}
		cout << endl;
	}
};
class MultiplyBy20 : public Counter {
public:
	void Count(int st) {
		for (int i = 0; i <= 20 * st; i += 2) {
			cout << i << " ";
		}
		cout << endl;
	}
};
class MultiplyBy30 : public Counter {
public:
	void Count(int st) {
		for (int i = 0; i <= 30 * st; i += 2) {
			cout << i << " ";
		}
		cout << endl;
	}
};
/*
int main() {
	Counter* By10 = new MultiplyBy10();
	Counter* By20 = new MultiplyBy20();
	Counter* By30 = new MultiplyBy30();
	vector<Counter*> v;
	v.push_back(By10);
	v.push_back(By20);
	v.push_back(By30);
	int x = 5;
	for (int i = 0; i < v.size(); i++) v[i]->Count(x);
	delete By10;
	delete By20;
	delete By30;



	// Use unique_ptr
}
*/