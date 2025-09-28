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
public:
	string Name;
	string Content;
	Status st;
	Reviewer& rvw;
	Approver& apv;
	Task(string& n, string& c,Status s, Approver& a, Reviewer& r) : Name(n),Content(c),st(s),apv(a),rvw(r) {}
	void Info() {
		cout << Name << "\n" << Content << "\n-----------\n";
	}
};

class TasksHistory {
public:
	vector<unique_ptr<Task>> tsks;
	void AddTask(unique_ptr<Task>&& t) {
		tsks.push_back(move(t));
	}
};

class Admin {
public:
	string Name;
	TasksHistory& th;
	Admin(string& n, TasksHistory& th) : Name(n),th(th) {}
	void pushTaskToApprover(unique_ptr<Task>&& tsk) {
		tsk->rvw.AddTask(move(tsk));
	}
};

class Reviewer {
public:
	string Name;
	TasksHistory& th;
	vector<unique_ptr<Task>> tsks;
	Reviewer(string& n, TasksHistory& th) : Name(n), th(th) {}
	void AddTask(unique_ptr<Task>&& t) {
		tsks.push_back(move(t));
	}
	void ApproveTask(unique_ptr<Task>&& t) {
		t->apv.AddTask(move(t));
	}
	void RejectTask(unique_ptr<Task>& t) {
		t->st = Rejected;
		th.AddTask(move(t));
	}
	void DisplayAllPendingTasks() {
		for (auto& t : tsks) {
			t->Info();
		}
	}
};

class Approver {
public:
	string Name;
	vector<unique_ptr<Task>> tsks;
	TasksHistory& th;
	Approver(string& n, TasksHistory& th) : Name(n), th(th) {}
	void AddTask(unique_ptr<Task>&& t) {
		tsks.push_back(move(t));
	}
	void ApproveTask(unique_ptr<Task>& t) {
		t->st = Approved;
		th.AddTask(move(t));
	}
	void RejectTask(unique_ptr<Task>& t) {
		t->st = Rejected;
		th.AddTask(move(t));
	}
	void DisplayAllPendingTasks() {
		for (auto& t : tsks) {
			t->Info();
		}
	}
};