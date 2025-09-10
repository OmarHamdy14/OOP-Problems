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
	vector<unique_ptr<Offer>> Offers;
	Seller(string& N) : Name(N) {}
	void CreateOffer(string& N, double P) {
		Offers.push_back(make_unique<Offer>(N, P));
	}
	void DisplayAllOffers() {
		cout << "Seller Name: " << Name << endl;
		for (auto& offer : Offers) {
			offer->DisplayInfo();
		}
	}
};
class Seller2 {
private:
	string Name;
	vector<Offer> Offers;

public:
	Seller2(const string& n) : Name(n) {}

	string GetName() const { return Name; }

	void CreateOffer(const string& n, double p) {
		Offers.emplace_back(n, p);
	}

	void RemoveOffer(size_t index) {
		if (index < Offers.size()) {
			Offers.erase(Offers.begin() + index);
		}
		else {
			cout << "Invalid offer index!\n";
		}
	}

	const vector<Offer>& GetOffers() const { return Offers; }

	void DisplayAllOffers() const {
		cout << "Seller: " << Name << endl;
		if (Offers.empty()) {
			cout << "  No offers available.\n";
			return;
		}
		for (size_t i = 0; i < Offers.size(); ++i) {
			cout << "[" << i << "] ";
			Offers[i].DisplayInfo();
		}
	}
};
class Buyer {
public:
	string Name;
	vector<unique_ptr<Offer>> Purchases;
	Buyer(string& N) : Name(N) {}
};
class Transaction {
public:
	Seller seller;
	Buyer buyer;
	Offer offer;
	void CreateTransaction(Seller& seller, Buyer& buyer, unique_ptr<Offer>& offer) {
		cout << "Seller Name: " << seller.Name << endl;
		cout << "Offer Details: ";
		offer->DisplayInfo();
		cout << "Buyer Name: " << buyer.Name << endl;
	}
};

class Transaction2 {
private:
	Buyer buyer;
	Seller* seller;
	Offer offer;

public:
	Transaction(const Buyer& b, Seller* s, const Offer& o)
		: buyer(b), seller(s), offer(o) {}

	void Process() {
		cout << "Transaction: " << buyer.GetName()
			<< " bought " << offer.GetName()
			<< " from " << seller->GetName()
			<< " for $" << offer.GetPrice() << endl;
	}
};

class Marketplace {
public:
	vector<unique_ptr<Transaction>> Transactions;
	void AddTransaction(unique_ptr<Transaction> tra) {
		Transactions.push_back(move(tra));
	}
	
};

class Seller {
private:
	string Name;
	vector<Offer> Offers;

public:
	Seller(const string& n) : Name(n) {}

	string GetName() const { return Name; }

	void CreateOffer(const string& n, double p) {
		Offers.emplace_back(n, p);
	}

	void RemoveOffer(size_t index) {
		if (index < Offers.size()) {
			Offers.erase(Offers.begin() + index);
		}
		else {
			cout << "Invalid offer index!\n";
		}
	}

	void DisplayAllOffers() const {
		cout << "Seller: " << Name << endl;
		if (Offers.empty()) {
			cout << "  No offers available.\n";
			return;
		}
		for (size_t i = 0; i < Offers.size(); ++i) {
			cout << "[" << i << "] ";
			Offers[i].DisplayInfo();
		}
	}
};