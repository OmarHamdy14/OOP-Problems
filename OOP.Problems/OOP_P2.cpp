/*
* Problem Statement
Make a class that includes another class as a variable. The included part should have its own method, 
and the main class should use that method.
*/
#include "OOP_P2.h"
#include <iostream>
#include <string>
using namespace std;

class CI_Faculty {
public:
	CS_Department CS_DEP;
	IT_Department IT_DEP;
	void DisplayInfoAboutCSDep() {
		CS_DEP.GetName();
		CS_DEP.GetStudentsNum();
		CS_DEP.GetStaffNum();
	}
	void DisplayInfoAboutITDep() {
		IT_DEP.GetName();
		IT_DEP.GetStudentsNum();
		IT_DEP.GetStaffNum();
	}
};
class CS_Department {
public:
	string Name;
	int Students_Num;
	int Staff_Num;
	CS_Department(string n, int StudNum, int StafNum) {
		Name = n;
		Students_Num = StudNum;
		Staff_Num = StafNum;
	}
	void GetName() {
		cout << Name << "/n";
	}
	void GetStudentsNum() {
		cout << Students_Num << "/n";
	}
	void GetStaffNum() {
		cout << Staff_Num << "/n";
	}
};
class IT_Department {
public:
	string Name;
	int Students_Num;
	int Staff_Num;
	IT_Department(string n, int StudNum, int StafNum) {
		Name = n;
		Students_Num = StudNum;
		Staff_Num = StafNum;
	}
	void GetName() {
		cout << Name << "/n";
	}
	void GetStudentsNum() {
		cout << Students_Num << "/n";
	}
	void GetStaffNum() {
		cout << Staff_Num << "/n";
	}
};
