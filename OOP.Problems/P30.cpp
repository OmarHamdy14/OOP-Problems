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
	const Reviewer& rvw;
	const Approver& apv;
public:
	Task(const string& n, const string& c,const Status& s, const Approver& a, const Reviewer& r) : Name(n),Content(c),st(s),apv(a),rvw(r) {}
	void Info() {
		cout << Name << "\n" << Content << "\n-----------\n";
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	const string& GetContent() const { return Content; }
	void SetContent(const string& n) { Content = n; }
	const Status& Getst() const { return st; }
	void Setst(const Status& n) { st = n; }
	const Reviewer& GetReviewer() const { return rvw; }
	const Approver& GetApprover() const { return apv; }
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
	Admin(const string& n, TasksHistory& th) : Name(n),th(th) {}
	void pushTaskToApprover(unique_ptr<Task>& tsk) {
		tsk->GetReviewer().AddTask(move(tsk));  // ???
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

class Reviewer {
	string Name;
	TasksHistory& th;
	vector<unique_ptr<Task>> tsks;
public:
	Reviewer(const string& n, TasksHistory& th) : Name(n), th(th) {}
	void AddTask(unique_ptr<Task>&& t) {
		tsks.push_back(move(t));
	}
	void ApproveTask(unique_ptr<Task>&& t) {
		t->GetApprover().AddTask(move(t));
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
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

class Approver {
	string Name;
	vector<unique_ptr<Task>> tsks;
	TasksHistory& th;
public:
	Approver(const string& n, TasksHistory& th) : Name(n), th(th) {}
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
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};