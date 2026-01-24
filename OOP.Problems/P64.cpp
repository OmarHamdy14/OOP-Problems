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
Online Food Delivery
Restaurants have menus.
Customers place orders.
Delivery agents deliver orders.
Order status changes over time.
*/

class MenuItem {
public:
    string name;
    double price;

    MenuItem(string n, double p) : name(n), price(p) {}
};


class Restaurant {
    string name;
    vector<MenuItem> menu;

public:
    Restaurant(string n) : name(n) {}

    void AddItem(string item, double price) {
        menu.emplace_back(item, price);
    }

    const vector<MenuItem>& GetMenu() const {
        return menu;
    }

    string GetName() const {
        return name;
    }
};


class Customer {
    string name;

public:
    Customer(string n) : name(n) {}
    string GetName() const { return name; }
};


class DeliveryAgent {
    string name;

public:
    DeliveryAgent(string n) : name(n) {}

    void Deliver() const {
        cout << name << " is delivering the order\n";
    }
};