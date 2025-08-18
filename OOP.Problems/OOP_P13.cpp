#include "OOP_P13.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;
/*
* Problem Statement
Build a communication system where users can send different types of messages (text, file, voice, etc.). 
The system should handle delivery, logging, and allow filtering by type or sender.
*/
class Person {
public:
	string Name;
};
class Message {
public:
	string Content;
	shared_ptr<Person> Sender;
	Message(shared_ptr<Person> s, string c) : Sender(s),Content(c) {}
	void Info() {
		cout << Sender->Name << ": " << Content << endl;
	}
};