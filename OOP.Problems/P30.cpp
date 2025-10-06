#include "P30.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Workflow Automation System
- Tasks move through steps with approvals/rejections.
- Different roles (Admin, Reviewer, Approver) interact differently.
*/
enum Status {
	Pending,
	Rejected,
	Approved
};
class Task {
	string Name;
	string Content;
	Status st;
	Reviewer& rvw;
	Approver& apv;
public:
	Task(string& n, string& c,Status s, Approver& a, Reviewer& r) : Name(n),Content(c),st(s),apv(a),rvw(r) {}
	void Info() {
		cout << Name << "\n" << Content << "\n-----------\n";
	}
	string GetName() const { return Name; }
	void SetName(string n) { Name = n; }
	string GetContent() const { return Content; }
	void SetContent(string n) { Content = n; }
	Status Getst() const { return st; }
	void Setst(Status n) { st = n; }
	Reviewer& GetReviewer() const { return rvw; }
	void SetReviewer(Reviewer& n) { rvw = n; }  // ???????????
	Approver& GetApprover() const { return apv; }
	void SetApprover(Approver& n) { apv = n; }  // ???????????
};

class TasksHistory {
	vector<unique_ptr<Task>> tsks;
public:
	void AddTask(unique_ptr<Task>&& t) {
		tsks.push_back(move(t));
	}
};

class Admin {
	string Name;
	TasksHistory& th;
public:
	Admin(string& n, TasksHistory& th) : Name(n),th(th) {}
	void pushTaskToApprover(unique_ptr<Task>&& tsk) {
		tsk->rvw.AddTask(move(tsk));
	}
	string GetName() const { return Name; }
	void SetName(string n) { Name = n; }
};

class Reviewer {
	string Name;
	TasksHistory& th;
	vector<unique_ptr<Task>> tsks;
public:
	Reviewer(string& n, TasksHistory& th) : Name(n), th(th) {}
	void AddTask(unique_ptr<Task>&& t) {
		tsks.push_back(move(t));
	}
	void ApproveTask(unique_ptr<Task>&& t) {
		t->apv.AddTask(move(t));
	}
	void RejectTask(unique_ptr<Task>& t) {
		t->Setst(Rejected);
		th.AddTask(move(t));
	}
	void DisplayAllPendingTasks() {
		for (auto& t : tsks) {
			t->Info();
		}
	}
	string GetName() const { return Name; }
	void SetName(string n) { Name = n; }
};

class Approver {
	string Name;
	vector<unique_ptr<Task>> tsks;
	TasksHistory& th;
public:
	Approver(string& n, TasksHistory& th) : Name(n), th(th) {}
	void AddTask(unique_ptr<Task>&& t) {
		tsks.push_back(move(t));
	}
	void ApproveTask(unique_ptr<Task>& t) {
		t->Setst(Approved);
		th.AddTask(move(t));
	}
	void RejectTask(unique_ptr<Task>& t) {
		t->Setst(Rejected);
		th.AddTask(move(t));
	}
	void DisplayAllPendingTasks() {
		for (auto& t : tsks) {
			t->Info();
		}
	}
	string GetName() const { return Name; }
	void SetName(string n) { Name = n; }
};