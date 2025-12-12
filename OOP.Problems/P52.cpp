#include "P52.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include<unordered_map>
using namespace std;

/*
* Problem Statement
E-Commerce with Inventory & Orders 
Products, Orders, and Payments. 
Different payment types (CreditCard, PayPal, Crypto). 
Inventory system composed inside Store; users aggregate orders.
*/


class Product {
    string name;
    double price;
public:
    Product(string n, double p) : name(n), price(p) {}
    string GetName() const { return name; }
    double GetPrice() const { return price; }
};

class Inventory {
    unordered_map<string, pair<Product, int>> stock; // faster
public:
    void AddProduct(const Product& p, int qty) {
        stock[p.GetName()] = { p, qty };
    }

    bool HasStock(const string& name, int qty) {
        return stock.count(name) && stock[name].second >= qty;
    }

    void Reduce(const string& name, int qty) {
        stock[name].second -= qty;
    }

    Product GetProduct(const string& name) {
        return stock[name].first;
    }
};

class Payment {
public:
    virtual string Type() const = 0;
    virtual bool Pay(double amount) = 0;
};

class CreditCardPayment : public Payment {
public:
    string Type() const override { return "CreditCard"; }
    bool Pay(double amount) override { return true; }
};

class PayPalPayment : public Payment {
public:
    string Type() const override { return "PayPal"; }
    bool Pay(double amount) override { return true; }
};

class OrderItem {
    Product product;
    int quantity;
public:
    OrderItem(Product p, int q) : product(p), quantity(q) {}
    double Total() const { return product.GetPrice() * quantity; }
    string Name() const { return product.GetName(); }
    int Qty() const { return quantity; }
};

class Order {
    vector<OrderItem> items;
    double total = 0.0;
    bool paid = false;
public:
    void AddItem(const OrderItem& i) {
        items.push_back(i);
        total += i.Total();
    }

    double Total() const { return total; }

    bool Pay(Payment& p) {
        paid = p.Pay(total);
        return paid;
    }

    bool IsPaid() const { return paid; }
};

class Store {
    Inventory inventory;
public:
    Inventory& GetInventory() { return inventory; }
};

class User {
    string name;
    vector<shared_ptr<Order>> orders;
public:
    User(string n) : name(n) {}

    shared_ptr<Order> CreateOrder() {
        auto o = make_shared<Order>();
        orders.push_back(o);
        return o;
    }

    void ShowOrders() {
        for (auto& o : orders)
            cout << o->Total() << "\n";
    }
};