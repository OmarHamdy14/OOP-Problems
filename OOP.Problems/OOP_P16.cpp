#include "OOP_P16.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Bank Account System 
- Model accounts (savings, checking) with deposit, withdraw, and balance. 
- Ensure overdrafts are prevented for savings, but checking might allow them.
*/
class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string& accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual ~Account() = default;          // EXPLAIN ??? ======

    virtual void Deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " into account " << accountNumber << endl;
    }

    virtual void Withdraw(double amount) = 0;

    double GetBalance() const {
        return balance;
    }

    const string& GetAccountNumber() const {
        return accountNumber;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(const string& accNum, double initialBalance)
        : Account(accNum, initialBalance) {}

    void Withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Savings " << accountNumber << endl;
        }
        else {
            cout << "Withdrawal denied! Savings account cannot be overdrawn.\n";
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string& accNum, double initialBalance, double overdraft)
        : Account(accNum, initialBalance), overdraftLimit(overdraft) {}

    void Withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Checking " << accountNumber << endl;
        }
        else {
            cout << "Withdrawal denied! Overdraft limit exceeded.\n";
        }
    }
};

int main() {
}
