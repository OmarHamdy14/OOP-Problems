#include "OOP_P22.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Task Manager
- Tasks have deadlines, priorities, and statuses.
- Users can filter tasks and mark them complete.
*/
enum Priority {
	High,
	Medium,
	Low
};
enum Status {
	NotStarted,
	InProgress,
	Completed
};

class Task {
	string Name;
	string Content;
	Status status = NotStarted;
	Priority priority;
public:
	Task(string n, string c,Priority p) : Name(n),Content(c),priority(p) {}
	void DisplayInfo() {
		cout << "Task Name: " << Name << "\n" << "Task Content: " << Content << "\n" << "Task Staus: " << status << "\n" << "Task Priority: " << priority << "\n";
	}
	string GetName() const { return Name; }
	void SetName(string n) { Name = n; }
	string GetContent() const { return Content; }
	void SetContent(string& n) { Content = n; }
	Status Getstatus() const { return status; }
	void Setstatus(Status n) { status = n; }
	Priority Getpriority() const { return priority; }
	void Setpriority(Priority n) { priority = n; }
};

class TaskManager {
	vector<unique_ptr<Task>> Tasks;
public:
	void AddTask(unique_ptr<Task>&& t) {
		Tasks.push_back(move(t));
	}
	void AddTask_2(string n, string c,Priority p) {
		Tasks.push_back(make_unique<Task>(n,c,p));
	}
	void StartTask(unique_ptr<Task>& t) {
		t->Setstatus(InProgress);
	}
	void MarkTaskAsComplete(unique_ptr<Task>& t ) {
		t->Setstatus(Completed);
	}
	void FilterByPriority(Priority p) {
		for (auto& tsk : Tasks) {
			if (tsk->Getpriority() == p) tsk->DisplayInfo();
		}
	}
};