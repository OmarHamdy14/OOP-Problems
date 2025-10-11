#include "P32.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Online Marketplace
- Buyers and sellers transact.
- Payments are held until delivery is confirmed.
*/
class Product {
	string Name;
	float Price;
	Seller& slr;
public:
	Product(const string& n, float p, const Seller& s) : Name(n),Price(p),slr(s) {}
	void Info() {
		cout << Name << "\n" << Price << "\n";
	}
    const string& GetName() const { return Name; }
    void SetName(const string& n) { Name = n; }
    float GetPrice() const { return Price; }
    void SetPrice(float n) { Price = n; }
    const Seller GetSeller() const { return slr; }
 };

class Escrow {
    float balance;
    bool released;
public:
    Escrow() : balance(0), released(false) {}
    void Hold(float amount) {
        balance += amount;
        released = false;
        cout << "Escrow holding $" << amount << endl;
    }
    void Release() {
        if (!released && balance > 0) {
            cout << "Escrow released $" << balance << " to seller." << endl;
            balance = 0;
            released = true;
        }
        else {
            cout << "No funds to release." << endl;
        }
    }
    void Refund() {
        if (!released && balance > 0) {
            cout << "Escrow refunded $" << balance << " to buyer." << endl;
            balance = 0;
            released = true;
        }
        else {
            cout << "No funds to refund." << endl;
        }
    }
    float Getbalance() const { return balance; }
    void Setbalance(float n) { balance = n; }
    bool Getreleased() const { return released; }
    void Setreleased(bool n) { released = n; }
};

class Buyer {
	string Name;
	vector<unique_ptr<Product>> purchs;
public:
	Buyer(const string& n) : Name(n) {}
	void Buy(unique_ptr<Product>&& p, Escrow& escrow) {  // why when i put " const " before " Escrow& escrow ", this gives me error ??? 
		purchs.push_back(move(p));
        escrow.Hold(p->GetPrice());
	}
    void DeliveryConfirm(Escrow& escrow) {
        cout << "Delivery is done\n";
        escrow.Release();
    }
    string GetName() const { return Name; }
    void SetName(string& n) { Name = n; }
};

class Seller {
	string Name;
public:
	Seller(const string& n) : Name(n) {}
    const string& GetName() const { return Name; }
    void SetName(const string& n) { Name = n; }
};

class Marketplace {
	vector<unique_ptr<Product>> prds;
public:
	void AddProduct(const Seller& s, const string& n, float p) {
		prds.push_back(make_unique<Product>(n, p, s));
	}
    void displayAllProducts() {
        for (auto& p : prds) {
            p->Info();
            cout << "Seller Name: " << p->GetSeller().GetName() << "\n";
        }
    }
};