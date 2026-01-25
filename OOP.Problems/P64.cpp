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

enum class OrderStatus {
    Placed,
    Preparing,
    OutForDelivery,
    Delivered
};

class Order {
    const Customer& customer;
    const Restaurant& restaurant;
    vector<MenuItem> items;
    OrderStatus status = OrderStatus::Placed;

public:
    Order(const Customer& c, const Restaurant& r)
        : customer(c), restaurant(r) {
    }

    void AddItem(const MenuItem& item) {
        items.push_back(item);
    }

    double TotalPrice() const {
        double total = 0;
        for (auto& i : items)
            total += i.price;
        return total;
    }

    void UpdateStatus(OrderStatus newStatus) {
        status = newStatus;
    }

    void AssignDelivery(const DeliveryAgent& agent) {
        UpdateStatus(OrderStatus::OutForDelivery);
        agent.Deliver();
    }

    void ShowSummary() const {
        cout << "\nCustomer: " << customer.GetName() << endl;
        cout << "Restaurant: " << restaurant.GetName() << endl;
        cout << "Items:\n";
        for (auto& i : items)
            cout << "- " << i.name << " ($" << i.price << ")\n";

        cout << "Total: $" << TotalPrice() << endl;
    }
};


int main() {
    Restaurant restaurant("Pizza");
    restaurant.AddItem("basterma", 8.5);
    restaurant.AddItem("chicken", 10);

    Customer customer("Omar");
    DeliveryAgent agent("mo");

    Order order(customer, restaurant);

    order.AddItem(restaurant.GetMenu()[0]);
    order.AddItem(restaurant.GetMenu()[1]);

    order.UpdateStatus(OrderStatus::Preparing);
    order.AssignDelivery(agent);
    order.UpdateStatus(OrderStatus::Delivered);

    order.ShowSummary();
}