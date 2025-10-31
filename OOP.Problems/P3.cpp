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
	Student(const string& n, int a, int l) { Name = n; age = a; level = l; }
	const string& GetName() { return Name; }
	int GetAge() const { return age; }
	int GetLevel() const { return level; }
	void SetName(const string& n) { Name = n; }
	void SetAge(int ag) { age = ag; }
	void SetLevel(int lv) { level = lv; }
};
class Department {
	string Name;
	vector<Student> students;
public:
	Department(const string& N) {
		Name = N;
	}
	void AddStudent(const Student& std) {     // watch const here ??
		students.push_back(std);
	}
	void DisplayAllStudentsInfo() {
		for (auto& student : students) {
			student.GetName();
			student.GetAge();
			student.GetLevel();

		}
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};
