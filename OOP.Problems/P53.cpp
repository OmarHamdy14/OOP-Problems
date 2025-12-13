#include "P53.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
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