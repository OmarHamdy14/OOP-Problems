#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

/*
* Problem Statement
Online Chat Application
Users send messages.
Messages can be text or file.
Chats store history.
Users can mute or block others.
*/

class Message {
protected:
    string sender;

public:
    Message(string s) : sender(s) {}
    virtual ~Message() = default;

    string GetSender() const { return sender; }
    virtual void Display() const = 0;
};


class TextMessage : public Message {
    string text;

public:
    TextMessage(string s, string t) : Message(s), text(t) {}

    void Display() const override {
        cout << sender << ": " << text << endl;
    }
};

class FileMessage : public Message {
    string filename;

public:
    FileMessage(string s, string f) : Message(s), filename(f) {}

    void Display() const override {
        cout << sender << " sent a file: " << filename << endl;
    }
};


class User {
    string name;
    set<string> blocked;
    set<string> muted;

public:
    User(string n) : name(n) {}

    string GetName() const { return name; }

    void Block(const string& user) {
        blocked.insert(user);
    }

    void Mute(const string& user) {
        muted.insert(user);
    }

    bool IsBlocked(const string& user) const {
        return blocked.count(user);
    }

    bool IsMuted(const string& user) const {
        return muted.count(user);
    }
};