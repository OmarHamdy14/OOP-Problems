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
	Question(const string& c,int m, int qn, const string& TA) : Content(c),Marks(m),QNum(qn),TrueAnswer(TA) {}
	virtual void Display() = 0;
	virtual const string& GetContent() const = 0;
	virtual void SetContent(const string& n) = 0;
	virtual int GetMarks() const = 0;
	virtual void SetMarks(int n) = 0;
	virtual int GetQNum() const = 0;
	virtual void SetQNum(int n) = 0;
	virtual const string& GetTrueAnswer() const = 0;
	virtual void SetTrueAnswer(const string& n) = 0;
};
class MCQ : public Question {
public:
	vector<string> Options;
	MCQ(const string& c, int m, int qn, const string& TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
	const string& GetContent() const override { return Content; }
	void SetContent(const string& n) override { Content = n; }
	int GetMarks() const override { return Marks; }
	void SetMarks(int n) override { Marks = n; }
	int GetQNum() const override { return QNum; }
	void SetQNum(int n) override { QNum = n; }
	const string& GetTrueAnswer() const override { return TrueAnswer; }
	void SetTrueAnswer(const string& n) override { TrueAnswer = n; }
};
class TrueFalse : public Question {
public:
	TrueFalse(const string& c, int m, int qn, const string& TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
	const string& GetContent() const override { return Content; }
	void SetContent(const string& n) override { Content = n; }
	int GetMarks() const override { return Marks; }
	void SetMarks(int n) override { Marks = n; }
	int GetQNum() const override { return QNum; }
	void SetQNum(int n) override { QNum = n; }
	const string& GetTrueAnswer() const override { return TrueAnswer; }
	void SetTrueAnswer(const string& n) override { TrueAnswer = n; }
};
class OpenEnded : public Question {
public:
	OpenEnded(const string& c, int m, int qn, const string& TA) : Question(c, m, qn, TA) {}
	void Display() override {
		cout << Content << "\n" << Marks << "\n";
	}
	const string& GetContent() const override { return Content; }
	void SetContent(const string& n) override { Content = n; }
	int GetMarks() const override { return Marks; }
	void SetMarks(int n) override { Marks = n; }
	int GetQNum() const override { return QNum; }
	void SetQNum(int n) override { QNum = n; }
	const string& GetTrueAnswer() const override { return TrueAnswer; }
	void SetTrueAnswer(const string& n) override { TrueAnswer = n; }
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
	Student(const string& n, int s) : Name(n), Score(s) {}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	int GetScore() const { return Score; }
	void SetScore(int n) { Score = n; }
};