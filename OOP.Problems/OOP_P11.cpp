#include "OOP_P11.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
* Problem Statement
Model an organization where different roles have access to different tools. Tools perform operations, and roles use them differently. 
Ensure that each role only uses the tools allowed for them.
*/

// =======================================> "Has-a relationship" <=======================================


class Tool {
protected:
	string Name;
public:
	Tool(string& N) : Name(N) {}
	virtual void work(string& userRole) = 0;
	virtual string GetName() const = 0;
	virtual void SetName(string& s) = 0;
};
class Tool_A : public Tool {
public:
	Tool_A(string& n) : Tool(n){}
	void work(string& userRole) override{
		cout << userRole << " use " << Name << endl;
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
};
class Tool_B : public Tool {
public:
	Tool_B(string& n) : Tool(n) {}
	void work(string& userRole) override {
		cout << userRole << " use " << Name << endl;
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
};
class Tool_C : public Tool {
public:
	Tool_C(string& n) : Tool(n) {}
	void work(string& userRole) override {
		cout << userRole << " use " << Name << endl;
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
};



class Role {
protected:
	string Name;
	vector<shared_ptr<Tool>> AllowedTools;
public:
	Role(string n) : Name(n) {}
	virtual void addTool(shared_ptr<Tool>& tool) = 0;
	virtual void DisplayWorkAllowedTools() = 0;
	virtual string GetName() const = 0;
	virtual void SetName(string& s) = 0;
};
class Manager : public Role {
public:
	Manager(string n) : Role(n) {}
	void addTool(shared_ptr<Tool>& tool) override {
		AllowedTools.push_back(tool);
	}
	void DisplayWorkAllowedTools() override {
		for (auto& tool : AllowedTools) {
			cout << tool->GetName() << endl;
			tool->work(Name);
		}
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
};
class SemiManager : public Role {
public:
	SemiManager(string n) : Role(n) {}
	void addTool(shared_ptr<Tool>& tool) override {
		AllowedTools.push_back(tool);
	}
	void DisplayWorkAllowedTools() override {
		for (auto& tool : AllowedTools) {
			cout << tool->GetName() << endl;
			tool->work(Name);
		}
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
};
class Assistant : public Role {
public:
	Assistant(string n) : Role(n) {}
	void addTool(shared_ptr<Tool>& tool) override {
		AllowedTools.push_back(tool);
	}
	void DisplayWorkAllowedTools() override {
		for (auto& tool : AllowedTools) {
			cout << tool->GetName() << endl;
			tool->work(Name);
		}
	}
	string GetName() const override { return Name; }
	void SetName(string& s) override { Name = s; }
};

int main() {
	shared_ptr<Tool> toolA = make_shared<Tool_A>("hh"); // unable to obtain mapped memory ???? ==============

	shared_ptr<Tool> toolB = make_shared<Tool_B>("hgg");
	shared_ptr<Tool> toolC = make_shared<Tool_C>("ggu");

	Manager OmarManager("OmarManager");
	SemiManager OmarSemiManager("OmarSemiManager");
	Assistant OmarAssistant("OmarAssistant");

	OmarManager.addTool(toolA);
	OmarManager.DisplayWorkAllowedTools();
}