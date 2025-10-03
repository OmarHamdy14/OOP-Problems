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
class Department { // does abstract classes can inherit from other classes ??
protected:
	string Name;
	int Students_Num;
	int Staff_Num;
public:
	Department(string n, int StudNum, int StafNum) {
		Name = n;
		Students_Num = StudNum;
		Staff_Num = StafNum;
	}
	virtual string GetName() const = 0;
	virtual int GetStudentsNum() const = 0;
	virtual int GetStaffNum() const = 0;
	virtual void SetName(string& s) = 0;
	virtual void SetStudentsNum(int sn) = 0;
	virtual void SetStaffNum(int sn) = 0;
};
class CS_Department : public Department { 
public:
	CS_Department(string n, int StudNum, int StafNum) : Department(n, StudNum, StafNum) {}
	string GetName() const override {
		return Name;
	}
	int GetStudentsNum() const override {
		return Students_Num;
	}
	int GetStaffNum() const override {
		return Staff_Num;
	}
	void SetName(string& s) override {
		Name = s;
	}
	void SetStudentsNum(int sn) override {
		Students_Num = sn;
	}
	void SetStaffNum(int sn) override {
		Staff_Num = sn;
	}
};
class IT_Department : public Department {
public:
	IT_Department(string n, int StudNum, int StafNum) : Department(n, StudNum, StafNum) {}
	string GetName() const override {
		return Name;
	}
	int GetStudentsNum() const override {
		return Students_Num;
	}
	int GetStaffNum() const override {
		return Staff_Num;
	}
	void SetName(string& s) override {
		Name = s;
	}
	void SetStudentsNum(int sn) override {
		Students_Num = sn;
	}
	void SetStaffNum(int sn) override {
		Staff_Num = sn;
	}
};
class CI_Faculty {
public:
	string Name;
	vector<Department> Depts;
	CI_Faculty(string& n) {
		Name = n;
	}
	void AddDepartment(Department& dpt) {
		Depts.push_back(dpt);
	}
	void DisplayInfoAboutDepts() {
		for(auto& dept : Depts) {
			cout << dept.GetName() << "\n";
			cout<<dept.GetStudentsNum() << "\n";
			cout<<dept.GetStaffNum() << "\n";
		}
	}
};