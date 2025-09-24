#include "P26.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Stock Trading System
- Users can place buy/sell orders.
- Orders are matched and executed in a transaction history.
*/
class Product {
public:
	string Name;
	float Price;
	Product(string& n,float p) : Name(n),Price(p) {}
	void Info() {
		cout << "Product Name: " << Name << "\n" << "Price: " << Price << "\n";
	}
};

class Buyer {
public:
	string Name;
	vector<unique_ptr<Product>> Purchases;
	void AddPurchase(unique_ptr<Product>&& p) {
		Purchases.push_back(move(p));
	}
	void DisplayAllPurchases() {
		for (auto& p : Purchases) {
			p->Info();
		}
	}
};
class Seller {
public:
	string Name;
	vector<unique_ptr<Product>> Sales;
	void AddSale(string& n, float pr) {
		Sales.push_back(make_unique<Product>(n,pr));
	}
	void DisplayAllSales() {
		for (auto& s : Sales) {
			s->Info();
		}
	}
};

class Transaction {
public:
	string ProductName;
	float Paid;
	Seller& slr;
	Buyer& byr;
	Transaction(string& pn, float pd, Seller& sl, Buyer& by) : ProductName(pn),slr(sl),byr(by),Paid(pd) {}
};

class History {
public:
	vector<unique_ptr<Transaction>> trs;
	void MakeTransaction(unique_ptr<Product>& pr, Seller& s, Buyer& b) {
		trs.push_back(make_unique<Transaction>(pr->Name, pr->Price, s, b));
		b.AddPurchase(move(pr));
	}
};