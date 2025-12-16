#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

/*
* Problem Statement
Banking Network
Banks manage multiple branches.
Each branch manages Accounts (Checking, Savings, Business) with shared and specialized behaviors.
Include transaction logging and fraud detection.
*/


class ITransactionLogger {
public:
    virtual void Log(const string& msg) = 0;
};

class ConsoleLogger : public ITransactionLogger {
public:
    void Log(const string& msg) override {
        cout << "[Transaction] " << msg << endl;
    }
};

class IFraudDetector {
public:
    virtual bool CheckFraud() = 0;
};

class SimpleFraudDetector : public IFraudDetector {
public:
    bool CheckFraud() override {
        
    }
};

class Account {
protected:
    string id;
    double balance;
    ITransactionLogger& logger;
    IFraudDetector& fraud;
public:
    Account(string i, double b, ITransactionLogger& l, IFraudDetector& f)
        : id(i), balance(b), logger(l), fraud(f) {
    }

    virtual bool Deposit(double amount) {
        balance += amount;
        logger.Log("");
        return true;
    }

    virtual bool Withdraw(double amount) {
        if (fraud.CheckFraud()) {
            return false;
        }
        if (balance < amount) {
            logger.Log("");
            return false;
        }
        balance -= amount;
        logger.Log("");
        return true;
    }

    double GetBalance() const { return balance; }
    string GetID() const { return id; }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string i, double b, ITransactionLogger& l, IFraudDetector& f)
        : Account(i, b, l, f) {
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string i, double b, ITransactionLogger& l, IFraudDetector& f)
        : Account(i, b, l, f) {
    }

    bool Withdraw(double amount) override {
        if (amount > 2000) { 
            logger.Log("");
            return false;
        }
        return Account::Withdraw(amount);
    }
};

class BusinessAccount : public Account {
public:
    BusinessAccount(string i, double b, ITransactionLogger& l, IFraudDetector& f)
        : Account(i, b, l, f) {
    }

    bool Withdraw(double amount) override {
        if (amount > 50000) {
            logger.Log("");
            return false;
        }
        return Account::Withdraw(amount);
    }
};

class Branch {
    string name;
    vector<shared_ptr<Account>> accounts;
public:
    Branch(string n) : name(n) {}

    void AddAccount(shared_ptr<Account> a) { accounts.push_back(a); }
    void ShowAccounts() {
        for (auto& a : accounts)
            cout << "  Account: " << a->GetID() << "B: " << a->GetBalance() << endl;
    }
};

class Bank {
    string name;
    vector<shared_ptr<Branch>> branches;
public:
    Bank(string n) : name(n) {}
    void AddBranch(shared_ptr<Branch> b) { branches.push_back(b); }
    void ShowAllAccounts() {
        cout << "Bank: " << name << endl;
        for (auto& b : branches)
            b->ShowAccounts();
    }
};



