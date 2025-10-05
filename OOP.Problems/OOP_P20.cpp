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
protected:
	string Content;
	int Marks;
	int QNum;
	string TrueAnswer;
public:
	Question(string& c,int m, int qn,string& TA) : Content(c),Marks(m),QNum(qn),TrueAnswer(TA) {}
	virtual void Display() = 0;
	virtual string GetContent() const = 0;
	virtual void SetContent(string& n) = 0;
	virtual int GetMarks() const = 0;
	virtual void SetMarks(int n) = 0;
	virtual int GetQNum() const = 0;
	virtual void SetQNum(int n) = 0;
	virtual string GetTrueAnswer() const = 0;
	virtual void SetTrueAnswer(string& n) = 0;
};
class MCQ : public Question {
public:
	vector<string> Options;
	MCQ(string& c, int m, int qn, string TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
	string GetContent() const override { return Content; }
	void SetContent(string& n) override { Content = n; }
	int GetMarks() const override { return Marks; }
	void SetMarks(int n) override { Marks = n; }
	int GetQNum() const override { return QNum; }
	void SetQNum(int n) override { QNum = n; }
	string GetTrueAnswer() const override { return TrueAnswer; }
	void SetTrueAnswer(string& n) override { TrueAnswer = n; }
};
class TrueFalse : public Question {
public:
	TrueFalse(string& c, int m, int qn, string TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
	string GetContent() const override { return Content; }
	void SetContent(string& n) override { Content = n; }
	int GetMarks() const override { return Marks; }
	void SetMarks(int n) override { Marks = n; }
	int GetQNum() const override { return QNum; }
	void SetQNum(int n) override { QNum = n; }
	string GetTrueAnswer() const override { return TrueAnswer; }
	void SetTrueAnswer(string& n) override { TrueAnswer = n; }
};
class OpenEnded : public Question {
public:
	OpenEnded(string& c, int m, int qn, string TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
	string GetContent() const override { return Content; }
	void SetContent(string& n) override { Content = n; }
	int GetMarks() const override { return Marks; }
	void SetMarks(int n) override { Marks = n; }
	int GetQNum() const override { return QNum; }
	void SetQNum(int n) override { QNum = n; }
	string GetTrueAnswer() const override { return TrueAnswer; }
	void SetTrueAnswer(string& n) override { TrueAnswer = n; }
};

class Quiz {
	vector<shared_ptr<Question>> Questions;
public:
};

class Student {
	string Name;
	vector<shared_ptr<Quiz>> Quizzes;
	int Score;
public:
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
	int GetScore() const { return Score; }
	void SetScore(int n) { Score = n; }
};