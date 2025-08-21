#include "OOP_P14.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;
/*
* Problem Statement
Implement a virtual marketplace. Sellers can list offerings, buyers can place requests, and transactions happen 
between them. Each transaction involves multiple steps, and the system manages those steps across different roles.
*/
class Offer {
public:
	string Name;
	double Price;
	Offer(string& n,double p) : Name(n),Price(p) {}
	void DisplayInfo() {
		cout << Name << " " << Price << endl;
	}
};
class Seller {
public:
	string Name;
	vector<Offer> Offers;
	Seller(string& N) : Name(N) {}
	void CreateOffer(string& N, double P) {
		Offers.push_back(Offer(N, P));
	}
	void DisplayAllOffers() {
		cout << "Seller Name: " << Name << endl;
		for (auto& offer : Offers) {
			offer.DisplayInfo();
		}
	}
};
class Buyer {
public:
	string Name;
	Buyer(string& N) : Name(N) {}

};
class Transaction {
public:
	Seller seller;
	Buyer buyer;
	Offer offer;
	Transaction(Seller s,Buyer b,Offer o) : seller(s),buyer(b),offer(o) {}
};
class Marketplace {
	vector<Transaction> Transactions;
};
