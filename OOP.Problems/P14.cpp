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
	string Name;
	double Price;
public:
	Offer(const string& n,double p) : Name(n),Price(p) {}
	void DisplayInfo() {
		cout << Name << " " << Price << endl;
	}
	const string& GetName() const { return Name; }
	void SetName(const string& s) { Name = s; }
	double GetPrice() const { return Price; }
	void SetPrice(double p) { Price = p; }
};
class Seller {
	string Name;
	vector<unique_ptr<Offer>> Offers;
public:
	Seller(const string& N) : Name(N) {}
	void CreateOffer(const string& N, double P) {
		Offers.push_back(make_unique<Offer>(N, P));
	}
	void DisplayAllOffers() {
		cout << "Seller Name: " << Name << endl;
		for (auto& offer : Offers) {
			offer->DisplayInfo();
		}
	}
	const string& GetName() const { return Name; }
	void SetName(const string& s) { Name = s; }
};

class Buyer {
	string Name;
	vector<unique_ptr<Offer>> Purchases;
public:
	Buyer(const string& N) : Name(N) {}
	void AddPurchase(unique_ptr<Offer>&& of) {
		Purchases.push_back(move(of));
	}
	const string& GetName() const { return Name; }
	void SetName(const string& s) { Name = s; }
};

class Transaction { // WHY using const here give me error ?
	Seller& seller;
	Buyer& buyer;
	string OfferName;
public:
	Transaction(const Seller& s, Buyer& b, unique_ptr<Offer>&& offer) : seller(s),buyer(b),OfferName(offer->GetName()) {
		cout << "Seller Name: " << seller.GetName() << endl;
		cout << "Offer Details: ";
		offer->DisplayInfo();
		cout << "Buyer Name: " << buyer.GetName() << endl;
		buyer.AddPurchase(move(offer));
	}
	//void CreateTransaction(Seller& seller, Buyer& buyer, unique_ptr<Offer>&& offer) {}
};

class Marketplace {
	string Name;
public:
	Marketplace(const string& n) : Name(n) {}
	vector<unique_ptr<Transaction>> Transactions;
	void AddTransaction(unique_ptr<Transaction>&& tra) {
		Transactions.push_back(move(tra));
	}
	const string& GetName() const { return Name; }
	void SetName(const string& s) { Name = s; }
};


/*
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
*/
/*
class Offer {
private:
	string Name;
	double Price;

public:
	Offer(const string& n, double p) : Name(n), Price(p) {}

	string GetName() const { return Name; }
	double GetPrice() const { return Price; }

	void DisplayInfo() const {
		cout << "  Offer: " << Name << " | Price: $" << Price << endl;
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
private:
	string Name;

public:
	Buyer(const string& n) : Name(n) {}

	string GetName() const { return Name; }

	void DisplayInfo() const {
		cout << "Buyer: " << Name << endl;
	}
};

class Transaction {
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
private:
	vector<Seller*> sellers;
	vector<Transaction> transactions;

public:
	void RegisterSeller(Seller* s) {
		sellers.push_back(s);
	}

	void ShowAllOffers() const {
		cout << "=== Marketplace Offers ===\n";
		for (auto s : sellers) {
			s->DisplayAllOffers();
			cout << endl;
		}
	}

	void BuyOffer(Buyer& buyer, Seller* seller, size_t index) {
		const vector<Offer>& offers = seller->GetOffers();
		if (index >= offers.size()) {
			cout << "Invalid offer index!\n";
			return;
		}

		Transaction tx(buyer, seller, offers[index]);
		transactions.push_back(tx);
		tx.Process();

		seller->RemoveOffer(index);
	}

	void ShowTransactions() const {
		cout << "=== Transactions Log ===\n";
		if (transactions.empty()) {
			cout << "No transactions yet.\n";
			return;
		}
		for (auto& t : transactions) {
			t.Process();
		}
	}
};

int main() {
	// Sellers
	Seller s1("Alice");
	Seller s2("Bob");

	s1.CreateOffer("Book", 12.5);
	s1.CreateOffer("Laptop", 800);
	s2.CreateOffer("Phone", 500);

	Buyer b1("Charlie");

	Marketplace mp;
	mp.RegisterSeller(&s1);
	mp.RegisterSeller(&s2);

	mp.ShowAllOffers();

	mp.BuyOffer(b1, &s1, 0);

	mp.ShowAllOffers();
	mp.ShowTransactions();

	return 0;
}

*/