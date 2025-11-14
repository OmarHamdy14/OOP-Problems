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
	Scene(const string& n, shared_ptr<Director>& dirc) : Description(n),dirc(dirc) {}
	const string& GetDescription() const { return Description; }
	void SetDescription(const string& t) { Description = t; }

	void AddActor(shared_ptr<Actor>& actr) {
		actrs.push_back(actr);
	}
	void AddProb(unique_ptr<Prob>&& prob) {
		probs.push_back(move(prob));
	}
	void AddEffect(unique_ptr<Effect>&& efct) {
		efcts.push_back(move(efct));
	}
};


class Movie {
	string Name;
	vector<unique_ptr<Scene>> scns;
public:
	void AddScene(unique_ptr<Scene>&& scn) {
		scns.push_back(move(scn));
	}
	Movie(const string& n) : Name(n) {}
	const string& GetName() const { return Name; }
	void SetName(const string& t) { Name = t; }
};

int main() {
	shared_ptr<Actor> actr1 = make_shared<Actor>("actr1");
	shared_ptr<Actor> actr2 = make_shared<Actor>("actr2");
	shared_ptr<Actor> actr3 = make_shared<Actor>("actr3");

	unique_ptr<Prob> prb1 = make_unique<Prob>("prb1");
	unique_ptr<Prob> prb2 = make_unique<Prob>("prb2");

	unique_ptr<Effect> efc1 = make_unique<Effect>("efc1");
	unique_ptr<Effect> efc2 = make_unique<Effect>("efc2");

	shared_ptr<Director> drc = make_shared<DramaDirector>("drc1");

	unique_ptr<Scene> sc1 = make_unique<Scene>("scene #1 about ......", drc);
	sc1->AddActor(actr1);
	sc1->AddProb(move(prb1));
	sc1->AddProb(move(prb2));
	sc1->AddEffect(move(efc1));

	Movie mov("mv-1");
	mov.AddScene(move(sc1));
}