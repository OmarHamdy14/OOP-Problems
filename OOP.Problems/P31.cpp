#include "P31.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
E-Learning Platform
- Teachers create courses, students enroll, assignments submitted.
- System tracks progress and generates certificates.
*/
class Course {
	string Name;
public:
	Course(string& n) : Name(n) {}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
};

class Student {
	string Name;
	vector<shared_ptr<Course>> cors;
public:
	void EnrollCourse(shared_ptr<Course>& c) {
		cors.push_back(c);
	}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
};

class Teacher {
	System& sys;
public:
	Teacher(System& s) : sys(s) {}
	void CreateCourse(string& n) {
		sys.AddCourse(make_shared<Course>(n));
	}
	System GetSystem() const { return sys; }
};

class System {
	vector<shared_ptr<Course>> crs;
public:
	void AddCourse(shared_ptr<Course> c) {
		crs.push_back(c);
	}
};