#include "OOP_P2.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

/*
* Problem Statement
Make a class that includes another class as a variable. The included part should have its own method, 
and the main class should use that method.
*/
class Department {
public:
	string Name;
	int Students_Num;
	int Staff_Num;
	Department(string n, int StudNum, int StafNum) {
		Name = n;
		Students_Num = StudNum;
		Staff_Num = StafNum;
	}
	virtual void GetName() = 0;
	virtual void GetStudentsNum() = 0;
	virtual void GetStaffNum() = 0;
};
class CS_Department : public Department {
public:
	CS_Department(string n, int StudNum, int StafNum) : Department(n, StudNum, StafNum) {}
	void GetName() override {
		cout << Name << "/n";
	}
	void GetStudentsNum() override {
		cout << Students_Num << "/n";
	}
	void GetStaffNum() override {
		cout << Staff_Num << "/n";
	}
};
class IT_Department : public Department {
public:
	IT_Department(string n, int StudNum, int StafNum) : Department(n, StudNum, StafNum) {}
	void GetName() override {
		cout << Name << "/n";
	}
	void GetStudentsNum() override {
		cout << Students_Num << "/n";
	}
	void GetStaffNum() override {
		cout << Staff_Num << "/n";
	}
};
class CI_Faculty {
public:
	string Name;
	vector<Department> Depts;
	CI_Faculty(string n) {
		Name = n;
	}
	void AddDepartment(Department& dpt) {
		Depts.push_back(dpt);
	}
	void DisplayInfoAboutDepts() {
		for(auto& dept : Depts) {
			dept.GetName();
			dept.GetStudentsNum();
			dept.GetStaffNum();
		}
	}
};