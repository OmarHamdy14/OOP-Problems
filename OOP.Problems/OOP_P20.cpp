#include "OOP_P20.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Online Quiz System
- Different question types (MCQ, True/False, Open-ended).
- Track answers and calculate scores.
*/
class Question {        // is abstraction always important ?? ========
public:
	string Content;
	int Marks;
	int QNum;
	string TrueAnswer;
	Question(string& c,int m, int qn,string& TA) : Content(c),Marks(m),QNum(qn),TrueAnswer(TA) {}
	virtual void Display() = 0;
};
class MCQ : public Question {
public:
	vector<string> Options;
	MCQ(string& c, int m, int qn, string TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
};
class TrueFalse : public Question {
public:
	TrueFalse(string& c, int m, int qn, string TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
};
class OpenEnded : public Question {
public:
	OpenEnded(string& c, int m, int qn, string TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
};

class Quiz {
public:
	vector<shared_ptr<Question>> Questions;
};

class Student {
public:
	string Name;
	vector<shared_ptr<Quiz>> Quizzes;
	int Score;
};