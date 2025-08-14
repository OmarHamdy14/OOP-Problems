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
public:
	string Name;
	Tool(string N) : Name(N) {}
	virtual void work(string& userRole) = 0;
};
class Tool_A : public Tool {
public:
	Tool_A(string n) : Tool(n){}
	void work(string& userRole) override{
		cout << userRole << " use " << Name << endl;
	}
};
class Tool_B : public Tool {
public:
	Tool_B(string n) : Tool(n) {}
	void work(string& userRole) override {
		cout << userRole << " use " << Name << endl;
	}
};
class Tool_C : public Tool {
public:
	Tool_C(string n) : Tool(n) {}
	void work(string& userRole) override {
		cout << userRole << " use " << Name << endl;
	}
};



class Role {
public:
	vector<shared_ptr<Tool>> AllowedTools;
	string Name;
	Role(string n) : Name(n) {}
	virtual void addTool(shared_ptr<Tool> tool) = 0;
	virtual void DisplayWorkAllowedTools() = 0;
};
class Manager : public Role {
public:
	Manager(string n) : Role(n) {}
	void addTool(shared_ptr<Tool> tool) override {
		AllowedTools.push_back(tool);
	}
	void DisplayWorkAllowedTools() override {
		for (auto& tool : AllowedTools) {
			cout << tool->Name << endl;
			tool->work(Name);
		}
	}
};
class SemiManager : public Role {
public:
	SemiManager(string n) : Role(n) {}
	void addTool(shared_ptr<Tool> tool) override {
		AllowedTools.push_back(tool);
	}
	void DisplayWorkAllowedTools() override {
		for (auto& tool : AllowedTools) {
			cout << tool->Name << endl;
			tool->work(Name);
		}
	}
};
class Assistant : public Role {
public:
	Assistant(string n) : Role(n) {}
	void addTool(shared_ptr<Tool> tool) override {
		AllowedTools.push_back(tool);
	}
	void DisplayWorkAllowedTools() override {
		for (auto& tool : AllowedTools) {
			cout << tool->Name << endl;
			tool->work(Name);
		}
	}
};

int main() {
	shared_ptr<Tool> toolA = make_shared<Tool_A>();
	shared_ptr<Tool> toolB = make_shared<Tool_B>();
	shared_ptr<Tool> toolC = make_shared<Tool_C>();

	Manager OmarManager("OmarManager");
	SemiManager OmarSemiManager("OmarSemiManager");
	Assistant OmarAssistant("OmarAssistant");

	OmarManager.addTool(toolA);
	OmarManager.DisplayWorkAllowedTools();
}