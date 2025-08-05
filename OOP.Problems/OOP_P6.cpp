#include "OOP_P6.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;
/*
* Problem Statement
Create a setup where one class works with a collection of others, which are created outside of it. The same secondary objects should be reusable elsewhere.
*/

class Course {
private:
    string name;
public:
    Course(const string& name) : name(name) {}
    string GetName() const { return name; }
};

class Student {
private:
    string name;
    vector<shared_ptr<Course>> Courses;
public:
    Student(const string& name, const vector<shared_ptr<Course>>& courses)
        : name(name), Courses(courses) {}

    void PrintCourses() const {
        std::cout << "Student: " << name << "\nCourses:\n";
        for (const auto& course : Courses) {
            std::cout << " * " << course->GetName() << "\n";
        }
    }
};
/*
int main() {
    auto science = make_shared<Course>("Science");
    auto english = make_shared<Course>("English");
    auto math = make_shared<Course>("Math");

    Student s1("Omar", { science,english,math });
    Student s2("Hamdy", { science,english,math });

    s1.PrintCourses();

}
*/