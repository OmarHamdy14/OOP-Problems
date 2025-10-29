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
Robot Assembly System
*/

class Arm {
	string Description;
	float Length;
	float Weight;
public:
	string GetDecription() const { return Description; }
	void SetDescription(string& n) { Description = n; }
	float GetLenght() const { return Length; }
	void SetLength(float n) { Length = n; }
	float GetWeight() const { return Weight; }
	void SetWeight(float n) { Weight = n; }

	void DoWrok() { cout << "work .. work ... work\n"; }
};

class Motor {
	string Description;
	float Power;
	float Weight;
public:
	const string GetDecription() const { return Description; }
	void SetDescription(const string& n) { Description = n; }
	float GetPower() const { return Power; }
	void SetPower(float n) { Power = n; }
	float GetWeight() const { return Weight; }
	void SetWeight(float n) { Weight = n; }

	void DoWrok() { cout << "work .. work ... work\n"; }
};

class AIController {
	string Description;
public:
	const string& GetDecription() const { return Description; }
	void SetDescription(const string& n) { Description = n; }

	void DoWrok() { cout << "work .. work ... work\n"; }
};

class Robot {
	Arm arm;
	Motor mtr;
	AIController cntr;
public:
	Robot(const Arm& d, const Motor& m, const AIController& a) : arm(d),mtr(m),cntr(a) {}
	const Arm& GetArm() const { return arm; }
	void SetArm(const Arm& d) { arm = d; }
	const Motor& GetMotor() const { return mtr; }
	void SetMotor(const Motor& d) { mtr = d; }
	const AIController& GetAIController() const { return cntr; }
	void SetAIController(const AIController& d) { cntr = d; }

	void PowerOn() {
		arm.DoWrok();
		mtr.DoWrok();
		cntr.DoWrok();
	}
};