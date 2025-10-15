#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
* Problem Statement
Build a system where a person can manage items in their possession. Each item should perform a different action, 
and the person interacts with them based on type and behavior.
*/
class Fruit {
protected:
	string Name;
	double Price;
public:
	Fruit(const string& n,double p) : Name(n),Price(p) {}
	virtual void InfoAboutFruit() = 0;
	virtual const string& GetName() const = 0;
	virtual double GetPrice() const = 0;
	virtual void SetName(const string& s) = 0;
	virtual void SetPrice(double sn) = 0;
};
class Apple : public Fruit {
public:
	Apple(const string& n,double p) : Fruit(n,p){}
	void InfoAboutFruit() override {
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
	}
	const string& GetName() const override { return Name; }
	double GetPrice() const override { return Price; }
	void SetName(const string& s) override { Name = s; }
	void SetPrice(double pr) override { Price = pr; }
};
class Orange : public Fruit {
	Orange(const string& n, double p) : Fruit(n, p) {}
	void InfoAboutFruit() override {
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
	}
	const string& GetName() const override { return Name; }
	double GetPrice() const override { return Price; }
	void SetName(const string& s) override { Name = s; }
	void SetPrice(double pr) override { Price = pr; }
};
class Date : public Fruit {
	Date(const string& n, double p) : Fruit(n, p) {}
	void InfoAboutFruit() override {
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
	}
	const string& GetName() const override { return Name; }
	double GetPrice() const override { return Price; }
	void SetName(const string& s) override { Name = s; }
	void SetPrice(double pr) override { Price = pr; }
};
class Person { // unique_ptr allows one owner only
	string Name;
	vector<unique_ptr<Fruit>> MyFruits;
public:
	Person(const string& n) : Name(n){} // if i put & after string in constructor, it gives error !!
	void AddFruit(unique_ptr<Fruit> F) { // is this right ? ========
		MyFruits.push_back(move(F));
	}
	void PrintMyFruits() {
		for (auto& fruit : MyFruits) {
			fruit->InfoAboutFruit();
		}
	}

	const string& GetName() const { return Name; }
	void SetName(const string& s) { Name = s; }
};