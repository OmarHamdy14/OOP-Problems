#include "P45.h"
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
Film Production Pipeline
*/

class Actor {
	string Name;
public:
	Actor(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }
};

class Prob {
	string Name;
public:
	Prob(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }

	void Work() const {
		cout << ".........\n";
	}
};

class Effect {
	string Name;
public:
	Effect(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }

	void Work() const {
		cout << ".........\n";
	}
};

class Director {
protected:
	string Name;
public:
	Director(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }
};
class DramaDirector : public Director {
public:

};
class ActionDirector : public Director {
public:

};


class Scene {
	string Description;
	shared_ptr<Director> dirc;
	vector<shared_ptr<Actor>> actrs;
	vector<unique_ptr<Prob>> probs;
	vector<unique_ptr<Effect>> efcts;
public:
	const string& GetDescription() const { return Description; }
	void SetDescription(const string& t) { Description = t; }

	void AddActor(shared_ptr<Actor>& actr) {
		actrs.push_back(actr);
	}
	void AddProb(unique_ptr<Prob>&& prob) {
		probs.push_back(move(prob));
	}
	void AddProb(unique_ptr<Effect>&& efct) {
		efcts.push_back(move(efct));
	}
};


class Movie {
	vector<unique_ptr<Scene>> scns;
public:
	void AddScene(unique_ptr<Scene>&& scn) {
		scns.push_back(move(scn));
	}
};