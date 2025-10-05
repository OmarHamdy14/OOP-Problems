#include "OOP_P18.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Shopping Cart
- Products can be added/removed.
- Discounts or coupons can be applied.
*/
class Product {
	string Name;
	double Price;
public:
	Product(string& n,double p) : Name(n),Price(p) {}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
	double GetPrice() const { return Price; }
	void SetPrice(double p) { Price = p; }
};

class Cart {
	vector<Product> Products;
public:
	void AddProduct(Product& Pr) {
		Products.push_back(move(Pr));
	}
	void RemoveProduct(string& name) {
		for (auto it = Products.begin(); it != Products.end(); ++it) {
			if (it->GetName() == name) { Products.erase(it); break; }
		}
	}
	void DisplayCart() {
		for (auto& p : Products) { cout << p.GetName() << " " << p.GetPrice() << endl; }
	}
};
