#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

/*
* Problem Statement
Financial Trading Platform
Traders place buy/sell orders.
MarketData feeds in price changes.
Strategies (Momentum, MeanReversion) define different trading behaviors.
*/

class Lesson {
    string title;
public:
    Lesson(string t) : title(t) {}
    string GetTitle() const { return title; }
};


class Assignment {
protected:
    string title;
public:
    Assignment(string t) : title(t) {}
    virtual double Evaluate(double submission) const = 0;
    string GetTitle() const { return title; }
};

class Homework : public Assignment {
public:
    Homework(string t) : Assignment(t) {}
    double Evaluate(double submission) const override {
        return submission;
    }
};

class Quiz : public Assignment {
public:
    Quiz(string t) : Assignment(t) {}
    double Evaluate(double submission) const override {
        return submission * 0.8;
    }
};

class Project : public Assignment {
public:
    Project(string t) : Assignment(t) {}
    double Evaluate(double submission) const override {
        return submission * 1.2 > 100 ? 100 : submission * 1.2;
    }
};

class Course {
    string name;
    vector<Lesson> lessons;
    vector<shared_ptr<Assignment>> assignments;
public:
    Course(string n) : name(n) {}

    void AddLesson(const Lesson& l) { lessons.push_back(l); }
    void AddAssignment(shared_ptr<Assignment> a) { assignments.push_back(a); }

    vector<shared_ptr<Assignment>>& GetAssignments() { return assignments; }
    string GetName() const { return name; }
};

class Instructor {
    string name;
public:
    Instructor(string n) : name(n) {}
    shared_ptr<Course> CreateCourse(string title) {
        return make_shared<Course>(title);
    }
};

class Student {
    string name;
    vector<shared_ptr<Course>> courses;
    unordered_map<string, double> grades;
public:
    Student(string n) : name(n) {}

    void Enroll(shared_ptr<Course> c) {
        courses.push_back(c);
    }

    void Submit(shared_ptr<Assignment> a, double score) {
        grades[a->GetTitle()] = a->Evaluate(score);
    }

    void ShowGrades() const {
        for (auto& g : grades)
            cout << g.first << " : " << g.second << "\n";
    }
};