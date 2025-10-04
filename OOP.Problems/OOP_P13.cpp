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
class User {
	string Name;
	vector<unique_ptr<Message>> RecievedMessages;
public:
	User(string& n) : Name(n) {}
	void DisplayUserInfo() {
		cout << "User Name: " << Name << endl;
	}
	void RecieveMessage(unique_ptr<Message>&& message) {
		RecievedMessages.push_back(move(message));
	}
	string GetName() const { return Name; }
	void SetName(string& s) { Name = s; }
};
class Message {
protected:
	string Content;
public:
	shared_ptr<User> Sender;
	shared_ptr<User> Recipient;
	Message(string& c, shared_ptr<User>& s, shared_ptr<User>& r) : Content(c),Sender(s),Recipient(r) {}
	virtual void DisplayMessageInfo() = 0;
	virtual string GetContent() const = 0;
	virtual void SetContent(string& c) = 0;
};
class TextMessage : public Message {
public:
	TextMessage(string& c, shared_ptr<User>& s, shared_ptr<User>& r) : Message(c,s,r) {}
	void DisplayMessageInfo() override {
		cout << "Type: Text" << endl << "Content: " << Content;
	}
	string GetContent() const override { return Content; }
	void SetContent(string& c) override { Content = c; }
};
class FileMessage : public Message {
public:
	FileMessage(string& c, shared_ptr<User>& s, shared_ptr<User>& r) : Message(c, s, r) {}
	void DisplayMessageInfo() override {
		cout << "Type: File" << endl << "Content: " << Content;
	}
	string GetContent() const override { return Content; }
	void SetContent(string& c) override { Content = c; }
};
class VoiceMessage : public Message {
public:
	VoiceMessage(string& c, shared_ptr<User>& s, shared_ptr<User>& r) : Message(c, s, r) {}
	void DisplayMessageInfo() override {
		cout << "Type: Voice" << endl << "Content: " << Content;
	}
	string GetContent() const override { return Content; }
	void SetContent(string& c) override { Content = c; }
};

class MessagesHistory {
	vector<unique_ptr<Message>> Messages;
public:
	void SaveMessage(unique_ptr<Message>&& message) {
		Messages.push_back(move(message));
	}
	void DisplayAllMessages() {
		for (auto& message : Messages) {
			cout << "From: " << message->Sender->GetName() << endl;
			cout << "To: " << message->Recipient->GetName() << endl;
			cout << "Message: " << message->GetContent() << endl;
		}
	}
	void DisplayAllMessagesBySenderName(string& SenderName) {
		for (auto& message : Messages) {
			if (message->Sender->GetName() == SenderName) {
				cout << "From: " << message->Sender->GetName() << endl;
				cout << "To: " << message->Recipient->GetName() << endl;
				cout << "Message: " << message->GetContent() << endl;
			}
		}
	}
};
class MessageDelivery {
	MessagesHistory& Logger;
public:
	MessageDelivery(MessagesHistory& L) : Logger(L){}
	void DeliverMessage(unique_ptr<Message>&& message, shared_ptr<User> Sender, shared_ptr<User> Recipient) {
		Logger.SaveMessage(move(message));
		Recipient->RecieveMessage(move(message));
	}
};




/*class Person {
public:
	string Name;
	vector<shared_ptr<Message>> RecievedMessages;
	void RecieveMessage(shared_ptr<Message> message) {
		RecievedMessages.push_back(message);
	}
};
class Message {
public:
	string Content;
	string Type;
	shared_ptr<Person> Sender;
	Message(shared_ptr<Person> s, string c, string t) : Sender(s),Content(c),Type(t) {}
	void Info() {
		cout << Sender->Name << ": " << Content << endl;
	}
	void SendMessage(shared_ptr<Person> recipient,shared_ptr<Message> message) {
		recipient->RecieveMessage(message);
	}
};
class MessagesHistory {
	vector<shared_ptr<Message>> Messages;
	void AddMessage(shared_ptr<Message> message) {
		Messages.push_back(message);
	}
};*/