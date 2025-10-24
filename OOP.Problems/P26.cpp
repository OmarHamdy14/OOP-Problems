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
	Product(const string& n,float p) : Name(n),Price(p) {}
	void Info() {
		cout << "Product Name: " << Name << "\n" << "Price: " << Price << "\n";
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
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
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};
class Seller {
	string Name;
	vector<unique_ptr<Product>> Sales;
public:
	void AddSale(const string& n, float pr) {
		Sales.push_back(make_unique<Product>(n,pr));
	}
	void DisplayAllSales() {
		for (auto& s : Sales) {
			s->Info();
		}
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
};

class Transaction {
	string ProductName;
	float Paid;
	const Seller& slr;
	const Buyer& byr;
public:
	Transaction(const string& pn, float pd, const Seller& sl, const Buyer& by) : ProductName(pn),slr(sl),byr(by),Paid(pd) {}
	const string& GetProductName() const { return ProductName; }
	void SetProductName(const string& n) { ProductName = n; }
	float GetPaid() const { return Paid; }
	void SetPaid(float n) { Paid = n; }
};

class History {
	vector<unique_ptr<Transaction>> trs;
public:
	void MakeTransaction(unique_ptr<Product>& pr, const Seller& s, Buyer& b) {
		trs.push_back(make_unique<Transaction>(pr->GetName(), pr->GetPrice(), s, b));
		b.AddPurchase(move(pr));
	}
};