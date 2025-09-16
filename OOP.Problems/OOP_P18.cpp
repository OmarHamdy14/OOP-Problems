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
public:
	string Name;
	double Price;
	Product(string& n,double p) : Name(n),Price(p) {}
};

class Cart {
public:
	vector<Product> Products;
	void AddProduct(Product& Pr) {
		Products.push_back(move(Pr));
	}
	void RemoveProduct(string& name) {
		for (auto it = Products.begin(); it != Products.end(); ++it) {
			if (it->Name == name) { Products.erase(it); break; }
		}
	}
	void DisplayCart() {
		for (auto& p : Products) { cout << p.Name << " " << p.Price << endl; }
	}
};
