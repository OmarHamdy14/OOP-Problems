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
public:
	string Name;
	int age;
	int level;
	Student(string n, int a, int l) { Name = n; age = a; level = l; }
	void GetName() {
		cout << Name << endl;
	}
	void GetAge() {
		cout << age << endl;
	}
	void GetLevel() {
		cout << level << endl;
	}
};
class Department {
public:
	string Name;
	vector<Student> students;
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
};
