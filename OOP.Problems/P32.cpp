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
public:
	string Name;
	float Price;
	Seller& slr;
	Product(string& n, float p, Seller& s) : Name(n),Price(p),slr(s) {}
	void Info() {
		cout << Name << "\n" << Price << "\n";
	}
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
};

class Buyer {
public:
	string Name;
	Buyer(string& n) : Name(n) {}
	vector<unique_ptr<Product>> purchs;
	void Buy(unique_ptr<Product>&& p, Escrow& escrow) {
		purchs.push_back(move(p));
        escrow.Hold(p->Price);
	}
    void DeliveryConfirm(Escrow& escrow) {
        cout << "Delivery is done\n";
        escrow.Release();
    }

};

class Seller {
public:
	string Name;
	Seller(string& n) : Name(n) {}
};

class Marketplace {
public:
	vector<unique_ptr<Product>> prds;
	void AddProduct(Seller& s, string& n, float p) {
		prds.push_back(make_unique<Product>(n, p, s));
	}
    void displayAllProducts() {
        for (auto& p : prds) {
            p->Info();
            cout << "Seller Name: " << p->slr.Name << "\n";
        }
    }
};