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
public:
    string TraderName;
    string Name;
    double Price;
    Order(const string& t, const string& n, double p)
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


class TradingPlatform {
    MarketData md;
    vector<unique_ptr<Trader>> traders;
    vector<Order> orderBook;
public:
    void AddTrader(unique_ptr<Trader> t) {
        traders.push_back(move(t));
    }

    void UpdateMarket(double newPrice) {
        md.UpdatePrice(newPrice);
    }

    void ShowOrders() {
        for (auto& o : orderBook) {
            cout << o.TraderName << " placed " << o.Name << "\n" << o.Price << "\n";
        }
    }
};

int main() {
    TradingPlatform platform;

    platform.AddTrader(make_unique<Trader>("aa", make_unique<MomentumStrategy>()));
    platform.AddTrader(make_unique<Trader>("bb", make_unique<MeanReversionStrategy>()));

    platform.UpdateMarket(10.5);
    platform.UpdateMarket(11.5);
    platform.UpdateMarket(12.5);

    platform.ShowOrders();
}