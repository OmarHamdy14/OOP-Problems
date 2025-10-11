#include "P33.h"
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
Tournament Engine (Esports)
- Teams register, brackets generated.
- Matches played with scoring and eliminations.
*/
class Team {
	string Name;
public:
	Team(const string& n) : Name(n) {}
	void RegisterToMatch(const Match& m) {

	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

class Match {
	int num;
	vector<shared_ptr<Team>> tms;
	Round& rnd;
public:
	Match(const Round& r, int n) : num(n), rnd(r) {}
	void Play() {
		int hlp = 0, idx = 0;
		for (int i = 0; i < tms.size(); i++) {
			int score = rand() % 10;
			if (score > hlp) { idx = i; hlp = score; }
		}
		cout << "The Winner Team is: " << tms[idx]->GetName() << "\n";
	}
	int Getnum() const { return num; }
	void Setnum(int n) { num = n; }
	const Round& GetRound() const { return rnd; }
};

class Round {
	string Name;
	vector<unique_ptr<Match>> mtchs;
	Tournament& trm;
public:
	Round(const Tournament& t, const string& n) : Name(n), trm(r) {}
	void AddMatch() {

	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	Tournament GetTournament() const { return trm; }
};

class Tournament {
	string Name;
	vector<shared_ptr<Team>> tms;
	vector<unique_ptr<Round>> rnds;
public:
	Tournament(const string& n) : Name(n) {}
	void RegisterToTournament(const Match& m) {

	}
	void AddRound(unique_ptr<Round>&& r) {

	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};