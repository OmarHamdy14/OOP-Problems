#include "OOP_P3.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
* Problem Statement
Write two classes where one accepts a group of the other as input. Those input objects are created separately and passed in.
*/
class Student {
	string Name;
	int age;
	int level;
public:
	Student(string n, int a, int l) { Name = n; age = a; level = l; }
	string GetName() { return Name; }
	int GetAge() const { return age; }
	int GetLevel() const { return level; }
	void SetName(string& n) { Name = n; }
	void SetAge(int ag) { age = ag; }
	void SetLevel(int lv) { level = lv; }
};
class Department {
	string Name;
	vector<Student> students;
public:
	Department(string N) {
		Name = N;
	}
	void AddStudent(Student& std) {
		students.push_back(std);
	}
	void DisplayAllStudentsInfo() {
		for (auto& student : students) {
			student.GetName();
			student.GetAge();
			student.GetLevel();

		}
	}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
};
