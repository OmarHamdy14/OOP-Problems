#include "OOP_P12.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Simulate a tournament where participants have different abilities. Each round, they perform actions, 
and their performance affects their standing. Include a system to manage rounds, scores, and eliminations.
*/ 
class Ability {
public:
	string Name;
	int Score;
	Ability(string& n,int s) : Name(n),Score(s) {}
	virtual void Perform() = 0;
};
class Speed : public Ability {
public:
	Speed(string& n, int s) : Ability(n,s) {}
	void Perform() override {
		cout << "Name: " << Name << endl << "Score: " << Score << endl;
	}
};
class Physical : public Ability {
public:
	Physical(string& n, int s) : Ability(n, s) {}
	void Perform() override {
		cout << "Name: " << Name << endl << "Score: " << Score << endl;
	}
};
class Fitness : public Ability {
public:
	Fitness(string& n, int s) : Ability(n, s) {}
	void Perform() override {
		cout << "Name: " << Name << endl << "Score: " << Score << endl;
	}
};
class Participant {
public:
	string Name;
	vector<shared_ptr<Ability>> Abilities;
	Participant(string n) : Name(n) {}
	void AddAbility(shared_ptr<Ability>& ability) {
		Abilities.push_back(ability);
	}
};
class ScoreBoard {
public:
	map<shared_ptr<Participant>, int> mpScore;
	void AddPartcipantScore(shared_ptr<Participant>& p) {
		mpScore[p] = 0;
	}
	void AddValueToScore(shared_ptr<Participant>& p, int value) {
		mpScore[p] += value;
	}
	void PrintStanding() {
		vector<pair< shared_ptr<Participant>, int>> standing(mpScore.begin(), mpScore.end());
		sort(standing.begin(), standing.end(), [](auto& a, auto& b) { return a.second > b.second; });
		for (int i = 0; i < standing.size(); i++) {
			cout << standing[i].first->Name << " " << standing[i].second << endl;
		}
	}
};
class Round {
public:
	string Name;
	vector<shared_ptr<Participant>> Participants;
	ScoreBoard scoreBoard;
	Round(string& n, ScoreBoard SB) : Name(n), scoreBoard(SB) {}
	void AddParticipant(shared_ptr<Participant>& Participant) {
		Participants.push_back(Participant);
	}
};
class Competition {
public:
	string Name;
	vector<unique_ptr<Round>> rounds;
	Competition(string n) : Name(n) {}
	void AddRound(unique_ptr<Round>&& r) {
		rounds.push_back(move(r));
	}
	void PrintResultsOfRounds(){
	}
};