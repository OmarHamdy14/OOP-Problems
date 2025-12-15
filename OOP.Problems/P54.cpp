#include "P54.h"
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




