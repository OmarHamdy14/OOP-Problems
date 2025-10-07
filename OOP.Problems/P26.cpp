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
	string Name;
	float Price;
public:
	Product(string& n,float p) : Name(n),Price(p) {}
	void Info() {
		cout << "Product Name: " << Name << "\n" << "Price: " << Price << "\n";
	}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
	float GetPrice() const { return Price; }
	void SetPrice(float n) { Price = n; }
};

class Buyer {
	string Name;
	vector<unique_ptr<Product>> Purchases;
public:
	void AddPurchase(unique_ptr<Product>&& p) {
		Purchases.push_back(move(p));
	}
	void DisplayAllPurchases() {
		for (auto& p : Purchases) {
			p->Info();
		}
	}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
};
class Seller {
	string Name;
	vector<unique_ptr<Product>> Sales;
public:
	void AddSale(string& n, float pr) {
		Sales.push_back(make_unique<Product>(n,pr));
	}
	void DisplayAllSales() {
		for (auto& s : Sales) {
			s->Info();
		}
	}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
};

class Transaction {
	string ProductName;
	float Paid;
	Seller& slr;
	Buyer& byr;
public:
	Transaction(string& pn, float pd, Seller& sl, Buyer& by) : ProductName(pn),slr(sl),byr(by),Paid(pd) {}
	string GetProductName() const { return ProductName; }
	void SetProductName(string& n) { ProductName = n; }
	float GetPaid() const { return Paid; }
	void SetPaid(float n) { Paid = n; }
};

class History {
	vector<unique_ptr<Transaction>> trs;
public:
	void MakeTransaction(unique_ptr<Product>& pr, Seller& s, Buyer& b) {
		trs.push_back(make_unique<Transaction>(pr->GetName(), pr->GetPrice(), s, b));
		b.AddPurchase(move(pr));
	}
};