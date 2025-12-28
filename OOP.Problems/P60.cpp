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
Event-Driven Stock Exchange
Traders → strategies.
Orders → limit/market/stop.
Exchange engine matches orders using multiple algorithms.
*/

struct MarketEvent {
    double price;
};


enum class OrderType { BUY, SELL };

class Order {
protected:
    OrderType side;
    int quantity;
public:
    Order(OrderType s, int q) : side(s), quantity(q) {}

    OrderType GetType() const { return side; }
    int GetQuantity() const { return quantity; }

    virtual bool CanExecute(double marketPrice) const = 0;
    virtual double GetPrice() const = 0;
};

class MarketOrder : public Order {
public:
    MarketOrder(OrderType s, int q) : Order(s, q) {}
    bool CanExecute(double) const override { return true; }
    double GetPrice() const override { return 0.0; }
};

class LimitOrder : public Order {
    double limitPrice;
public:
    LimitOrder(OrderType s, int q, double p) : Order(s, q), limitPrice(p) { }

    bool CanExecute(double marketPrice) const override {
        return side == OrderType::BUY
            ? marketPrice <= limitPrice
            : marketPrice >= limitPrice;
    }

    double GetPrice() const override { return limitPrice; }
};

class StopOrder : public Order {
    double stopPrice;
public:
    StopOrder(OrderType s, int q, double p) : Order(s, q), stopPrice(p) { }

    bool CanExecute(double marketPrice) const override {
        return side == OrderType::BUY
            ? marketPrice >= stopPrice
            : marketPrice <= stopPrice;
    }

    double GetPrice() const override { return stopPrice; }
};

class TradingStrategy {
public:
    virtual shared_ptr<Order> OnMarketEvent(const MarketEvent& e) = 0;
};

class MomentumStrategy : public TradingStrategy {
public:
    shared_ptr<Order> OnMarketEvent(const MarketEvent& e) override {
        if (e.price > 100)
            return make_shared<MarketOrder>(OrderType::BUY, 10);
        return nullptr;
    }
};

class MeanReversionStrategy : public TradingStrategy {
public:
    shared_ptr<Order> OnMarketEvent(const MarketEvent& e) override {
        if (e.price > 120)
            return make_shared<LimitOrder>(OrderType::SELL, 5, e.price);
        return nullptr;
    }
};


class Trader {
    string name;
    unique_ptr<TradingStrategy> strategy;
public:
    Trader(const string& n, unique_ptr<TradingStrategy> s)
        : name(n), strategy(move(s)) {
    }

    shared_ptr<Order> React(const MarketEvent& e) {
        auto order = strategy->OnMarketEvent(e);
        if (order)
            cout << name << " placed an order\n";
        return order;
    }
};
