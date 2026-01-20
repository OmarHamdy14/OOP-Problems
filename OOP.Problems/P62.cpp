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
Coffee Shop System
A CoffeeShop sells drinks.
Drinks can be Coffee, Tea, or Juice.
Customers place orders.
Orders calculate total price.
Some drinks have extras (milk, sugar).
*/

class Drink {
public:
    virtual ~Drink() = default;
    virtual string Name() const = 0;
    virtual double Price() const = 0;
};



class Coffee : public Drink {
public:
    string Name() const override { return "Coffee"; }
    double Price() const override { return 3.0; }
};

class Tea : public Drink {
public:
    string Name() const override { return "Tea"; }
    double Price() const override { return 2.5; }
};

class Juice : public Drink {
public:
    string Name() const override { return "Juice"; }
    double Price() const override { return 4.0; }
};


class DrinkExtra : public Drink {
protected:
    unique_ptr<Drink> base;
public:
    DrinkExtra(unique_ptr<Drink> d) : base(move(d)) {}
};

class Milk : public DrinkExtra {
public:
    Milk(unique_ptr<Drink> d) : DrinkExtra(move(d)) {}
    string Name() const override { return base->Name() + " + Milk"; }
    double Price() const override { return base->Price() + 0.5; }
};

class Sugar : public DrinkExtra {
public:
    Sugar(unique_ptr<Drink> d) : DrinkExtra(move(d)) {}
    string Name() const override { return base->Name() + " + Sugar"; }
    double Price() const override { return base->Price() + 0.2; }
};