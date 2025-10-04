#include "OOP_P6.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
* Problem Statement
Create a setup where one class works with a collection of others, which are created outside of it. 
The same secondary objects should be reusable elsewhere.
*/

class Course {
    string name;
public:
    Course(string& name) : name(name) {}
    string GetName() const { return name; }
    void SetName(string& n) { name = n; }
};

class Student {
    string name;
    vector<shared_ptr<Course>> Courses;
public:
    Student(string& name) : name(name){}

    void AddCourse(shared_ptr<Course> crs) {
        Courses.push_back(crs);
    }

    void PrintCourses() const {
        std::cout << "Student: " << name << "\nCourses:\n";
        for (const auto& course : Courses) {
            std::cout << " * " << course->GetName() << "\n";
        }
    }

    string GetName() const { return name; }
    void SetName(string& n) { name = n; }
};