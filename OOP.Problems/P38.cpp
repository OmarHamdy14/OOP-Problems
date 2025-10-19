#include "P38.h"
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
Hospital Management System
*/
class Doctor {
	string Name;
public:
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	void Work() { cout << "Work ... Work ... Work\n"; }
};

class Department {
	string Name;
	vector<shared_ptr<Doctor>> docts;
public:
	void AddDoctor(shared_ptr<Doctor>& d) {
		docts.push_back(d);
	}
	void DepartmentInfo() const {
		cout << Name << "\n";
		for (auto& d : docts) {
			cout << d->GetName() << "\n";
		}
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

class Hospital {
	string Name;
	vector<unique_ptr<Department>> depts;
public:
	void AddDepartment(unique_ptr<Department>&& d) {
		depts.push_back(move(d));
	}
	void HospitalInfo() const {
		cout << Name << "\n";
		for (auto& d : depts) {
			cout << d->GetName() << "\n";
		}
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};