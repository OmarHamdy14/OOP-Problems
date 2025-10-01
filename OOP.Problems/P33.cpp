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
public:
	string Name;
	Team(string& n) : Name(n) {}
	void RegisterToMatch(Match& m) {

	}
};

class Match {
public:
	int num;
	vector<shared_ptr<Team>> tms;
	Round& rnd;
	Match(Round& r, int n) : num(n), rnd(r) {}
	void Play() {
		int hlp = 0, idx = 0;
		for (int i = 0; i < tms.size(); i++) {
			int score = rand() % 10;
			if (score > hlp) { idx = i; hlp = score; }
		}
		cout << "The Winner Team is: " << tms[idx]->Name << "\n";
	}
};

class Round {
public:
	string Name;
	vector<unique_ptr<Match>> mtchs;
	Tournament& trm;
	Round(Tournament& t, string& n) : Name(n), trm(r) {}
	void AddMatch() {

	}
};

class Tournament {
public:
	string Name;
	vector<shared_ptr<Team>> tms;
	vector<unique_ptr<Round>> rnds;
	Tournament(string& n) : Name(n) {}
	void RegisterToTournament(Match& m) {

	}
	void AddRound(unique_ptr<Round>&& r) {

	}
};