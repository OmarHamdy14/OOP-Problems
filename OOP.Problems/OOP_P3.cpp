/*
* Problem Statement
Write two classes where one accepts a group of the other as input. Those input objects are created separately and passed in.
*/
#include "OOP_P3.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Department {
public:
	string Name;
	vector<Student> students;
	Department(string N, vector<Student> st) {
		Name = N;
		students = st;
	}
	void DisplayAllStudentsInfo() {
		for (int i = 0; i < students.size(); i++) {
			students[i].GetName();
			students[i].GetAge();
			students[i].GetLevel();
		}
	}
};
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
int main() {

}