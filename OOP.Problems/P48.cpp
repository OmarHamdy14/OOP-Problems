#include "P48.h"
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
AI Workflow System
Tasks like DataCleaning, ModelTraining, and Evaluation implement a shared interface.
A PipelineManager composes them into dynamic workflows.
Each task may depend on output of previous ones.
*/

class Task {
protected:
	string Name;
public:
	Task(const string& n) : Name(n) {}
	virtual const string& DoWork(const string& data) const = 0;
};
class DataCleaning : public Task {
public:
	DataCleaning(const string& n) : Task(n) {}
	const string& DoWork(const string& data) const override {
		cout << Name << " ................\n";
		return data;
	}
};
class ModelTraining : public Task {
public:
	ModelTraining(const string& n) : Task(n) {}
	const string& DoWork(const string& data) const override {
		cout << Name << " ................\n";
	}
};
class Evaluation : public Task {
public:
	Evaluation(const string& n) : Task(n) {}
	const string& DoWork(const string& data) const override {
		cout << Name << " ................\n";
	}
};

class Workflow {
	string Title;
	string Data;
	vector<shared_ptr<Task>> tsks;
public:
	Workflow(const string& t,const string& d) : Title(t),Data(d) {}
	void AddTask(shared_ptr<Task>& t) {
		tsks.push_back(t);
	}
	const string& DoWork() const {
		string res = Data;
		for(auto& tsk : tsks)
		{
			res = tsk->DoWork(res);
		}
		return res;
	}
};

class PipelineManager {
	vector<unique_ptr<Workflow>> wflows;
public:
	void AddTaskToWorkflow(shared_ptr<Task>& t, unique_ptr<Workflow>&& wfl) {
		wfl->AddTask(t);
	}
	void AddWorkflow(unique_ptr<Workflow>&& wfl) {
		wflows.push_back(move(wfl));
	}
};

int main() {
	shared_ptr<Task> DC = make_shared<DataCleaning>("..");
	shared_ptr<Task> MT = make_shared<ModelTraining>("..");

	unique_ptr<Workflow> wf = make_unique<Workflow>("..", "..");

	PipelineManager PM;
	PM.AddWorkflow(move(wf));
	PM.AddTaskToWorkflow(DC, move(wf));
}