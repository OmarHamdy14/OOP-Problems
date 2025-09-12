#include "OOP_P17.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Course {
    string name;
    double grade;
public:
    Course(const string& n, double g) : name(n), grade(g) {}
    double GetGrade() const { return grade; }
    string GetName() const { return name; }
};

class Student {
    string name;
    vector<Course> courses;
public:
    Student(const string& n) : name(n) {}
    void Enroll(const Course& c) { courses.push_back(c); }
    double CalculateGPA() const {
        if (courses.empty()) return 0.0;
        double sum = 0;
        for (auto& c : courses) sum += c.GetGrade();
        return sum / courses.size();
    }
    void DisplayInfo() const {
        cout << "Student: " << name << endl;
        for (auto& c : courses) {
            cout << "  " << c.GetName() << " : " << c.GetGrade() << endl;
        }
        cout << "GPA: " << CalculateGPA() << endl;
    }
};