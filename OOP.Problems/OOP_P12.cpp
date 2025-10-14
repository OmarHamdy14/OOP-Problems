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
protected:
	string Name;
	int Score;
public:
	Ability(const string& n,int s) : Name(n),Score(s) {}
	virtual void Perform() = 0;
	virtual const string& GetName() const = 0;
	virtual void SetName(const string& s) = 0;
	virtual int GetScore() const = 0;
	virtual void SetScore(int s) = 0;
};
class Speed : public Ability {
public:
	Speed(const string& n, int s) : Ability(n,s) {}
	void Perform() override {
		cout << "Name: " << Name << endl << "Score: " << Score << endl;
	}
	const string& GetName() const override { return Name; }
	void SetName(const string& s) override { Name = s; }
	int GetScore() const override { return Score; }
	void SetScore(int s) override { Score = s; }
};
class Physical : public Ability {
public:
	Physical(const string& n, int s) : Ability(n, s) {}
	void Perform() override {
		cout << "Name: " << Name << endl << "Score: " << Score << endl;
	}
	const string& GetName() const override { return Name; }
	void SetName(const string& s) override { Name = s; }
	int GetScore() const override { return Score; }
	void SetScore(int s) override { Score = s; }
};
class Fitness : public Ability {
public:
	Fitness(const string& n, int s) : Ability(n, s) {}
	void Perform() override {
		cout << "Name: " << Name << endl << "Score: " << Score << endl;
	}
	const string& GetName() const override { return Name; }
	void SetName(const string& s) override { Name = s; }
	int GetScore() const override { return Score; }
	void SetScore(int s) override { Score = s; }
};
class Participant {
	string Name;
	vector<shared_ptr<Ability>> Abilities;
public:
	Participant(const string& n) : Name(n) {}
	void AddAbility(shared_ptr<Ability>& ability) {
		Abilities.push_back(ability);
	}
	const string& GetName() const { return Name; }
	void SetName(const string& s) { Name = s; }
};
class ScoreBoard {
	map<shared_ptr<Participant>, int> mpScore;
public:
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
			cout << standing[i].first->GetName() << " " << standing[i].second << endl;
		}
	}
};
class Round {
	string Name;
	vector<shared_ptr<Participant>> Participants;
	const ScoreBoard scoreBoard;           // why const here has no problem ???
public:
	Round(const string& n, const ScoreBoard& SB) : Name(n), scoreBoard(SB) {}
	void AddParticipant(shared_ptr<Participant>& Participant) {
		Participants.push_back(Participant);
	}
	const string& GetName() const { return Name; }
	void SetName(const string& s) { Name = s; }
};
class Competition {
	string Name;
	vector<unique_ptr<Round>> rounds;
public:
	Competition(const string& n) : Name(n) {}
	void AddRound(unique_ptr<Round>&& r) {
		rounds.push_back(move(r));
	}
	void PrintResultsOfRounds(){
	}
	const string& GetName() const { return Name; }
	void SetName(const string& s) { Name = s; }
};