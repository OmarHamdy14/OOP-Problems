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
Financial Trading Platform
Traders place buy/sell orders.
MarketData feeds in price changes.
Strategies (Momentum, MeanReversion) define different trading behaviors.
*/

class MarketData {
    double price = 100.0;
public:
    double GetPrice() const { return price; }
    void UpdatePrice(double p) { price = p; }
};

class Order {
    string TraderName;
    string Name;
    double Price;
public:
    Order(const string& t, const string& n, double p, int q)
        : TraderName(t), Name(n), Price(p) {}
};

class TradingStrategy {
public:
    virtual void behavior() = 0;
};

class MomentumStrategy : public TradingStrategy {
    double lastPrice = 100.0;
public:
    void behavior() override
    {
        
    }
};

class MeanReversionStrategy : public TradingStrategy {
public:
    void behavior() override
    {
        
    }
};

class Trader {
    string name;
    unique_ptr<TradingStrategy> strategy;
public:
    Trader(const string& n, unique_ptr<TradingStrategy> s) : name(n), strategy(move(s)) {}

    const string& GetName() const { return name; }

    void Act(const MarketData& md) {
        strategy->behavior();
    }
};