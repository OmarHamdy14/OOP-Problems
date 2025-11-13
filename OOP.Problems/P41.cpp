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
Plugin Framework
*/

class Plugin {
public:
	virtual const string& GetName() const = 0;
	virtual void Work() const = 0;
};
class AnalyticsPlugin : public Plugin {
public:
	const string& GetName() const override {
		return "Analytics Plugin";
	}
	void Work() const override {
		cout << "Analytics Plugin is doing its work .....\n";
	}
};
class LimittingPlugin : public Plugin {
public:
	const string& GetName() const override {
		return "Limitting Plugin";
	}
	void Work() const override {
		cout << "Limitting Plugin is doing its work .....\n";
	}
};
class LoggingPlugin : public Plugin {
public:
	const string& GetName() const override {
		return "LoggingPlugin Plugin";
	}
	void Work() const override {
		cout << "Logging Plugin is doing its work .....\n";
	}
};

class PluginManager {
	vector<shared_ptr<Plugin>> plugins;
public:
	void AddPlugin(shared_ptr<Plugin> plg) {
		plugins.push_back(plg);
	}
	void ExcuteAll() {
		for (auto& plg : plugins) {
			plg->Work();
		}
	}
	void RemovePlugin(const string& plgName) {
		plugins.erase(remove_if(plugins.begin(), plugins.end(),
			[&](shared_ptr<Plugin>& p) { return p->GetName() == plgName; }),
			plugins.end());
	}
};