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
public:
	string Name;
	Course(string& n) : Name(n) {}
};

class Student {
public:
	string Name;
	vector<shared_ptr<Course>> cors;
	void EnrollCourse(shared_ptr<Course>& c) {
		cors.push_back(c);
	}
};

class Teacher {
public:
	System& sys;
	Teacher(System& s) : sys(s) {}
	void CreateCourse(string& n) {
		sys.AddCourse(make_shared<Course>(n));
	}
};

class System {
public:
	vector<shared_ptr<Course>> crs;
	void AddCourse(shared_ptr<Course> c) {
		crs.push_back(c);
	}
};