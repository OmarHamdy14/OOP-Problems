#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

    // Buyer
    Buyer b1("Charlie");

    // Marketplace
    Marketplace mp;
    mp.RegisterSeller(&s1);
    mp.RegisterSeller(&s2);

    mp.ShowAllOffers();

    // Buyer purchases something
    mp.BuyOffer(b1, &s1, 0);  // Charlie buys Alice's Book

    mp.ShowAllOffers();
    mp.ShowTransactions();

    return 0;
}
