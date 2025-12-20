#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

/*
* Problem Statement
Robotic Factory Line
Robots perform different tasks: welding, painting, assembly.
Tools attach/detach dynamically.
TaskScheduler optimizes workflow.
*/

class ITool {
public:
    virtual string Name() const = 0;
    virtual void Use() = 0;
};
class WelderTool : public ITool {
public:
    string Name() const override { return "Welder"; }
    void Use() override { cout << "Welding...\n"; }
};
class PaintTool : public ITool {
public:
    string Name() const override { return "PaintGun"; }
    void Use() override { cout << "Painting...\n"; }
};
class AssemblyTool : public ITool {
public:
    string Name() const override { return "Assembler"; }
    void Use() override { cout << "Assembling...\n"; }
};


class ITask {
public:
    virtual string Name() const = 0;
    virtual string RequiredTool() const = 0;
};
class WeldingTask : public ITask {
public:
    string Name() const override { return "Welding Task"; }
    string RequiredTool() const override { return "Welder"; }
};
class PaintingTask : public ITask {
public:
    string Name() const override { return "Painting Task"; }
    string RequiredTool() const override { return "PaintGun"; }
};
class AssemblyTask : public ITask {
public:
    string Name() const override { return "Assembly Task"; }
    string RequiredTool() const override { return "Assembler"; }
};

class Robot {
    unique_ptr<ITool> tool;
public:
    Robot() {}

    void AttachTool(unique_ptr<ITool> t) { tool = move(t); }
    void DetachTool() { tool.reset(); }

    bool CanPerform(const ITask& task) const {
        return tool && tool->Name() == task.RequiredTool();
    }

    void Perform(const ITask& task) {
        tool->Use();
    }
};

class TaskScheduler {
    vector<shared_ptr<Robot>> robots;
public:
    void AddRobot(shared_ptr<Robot> rb) { robots.push_back(rb); }

    void AssignTask(const ITask& task) {
        for (auto& r : robots) {
            if (r->CanPerform(task)) {
                r->Perform(task);
                return;
            }
        }
        cout << "No robot available for: " << task.Name() << "\n";
    }
};