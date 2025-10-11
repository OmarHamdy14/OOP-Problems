#include "P34.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
* Problem Statement
Virtual Stock Exchange Game
- Players trade with virtual money.
- Market prices fluctuate with events.
*/
class Stock {
	string Symbol;
	float Price;
public:
	Stock(const string& s,float p) : Symbol(s),Price(p) {}
	void Info() {
		cout << Symbol << " " << Price << "\n";
	}
	const string& GetSymbol() const { return Symbol; }
	void SetSymbol(const string& n) { Symbol = n; }
	float GetPrice() const { return Price; }
	void SetPrice(float n) { Price = n; }
};

class Player {
	string Name;
	float Balance;
	map<string, float> OwnStocks;
public:
	Player(const string& n, float b) : Name(n),Balance(b) {}
	void Buy(const Stock& st, int quantity) {
		float cost = quantity * st.GetPrice();
		if (Balance >= cost) {
			OwnStocks[st.GetSymbol()] += quantity;
			Balance -= st.GetPrice() * quantity;
		}
		else {
			cout << Name << " does not have enough balance." << endl;
		}
	}
	void Sell(const Stock& st, int quantity) {
		if (OwnStocks[st.GetSymbol()] >= quantity) {
			Balance += st.GetPrice() * quantity;
			OwnStocks[st.GetSymbol()] -= quantity;
		}
		else {
			cout << Name << " does not own enough shares." << endl;
		}
	}
	const string& GetName() const { return Name; }
	void SetName(const string& n) { Name = n; }
	float GetBalance() const { return Balance; }
	void SetBalance(float n) { Balance = n; }
};


class Market {
	vector<Stock> stcs;
public:
	void AddStock(string sym, float pr) {
		stcs.push_back(Stock(sym, pr));
	}
	void DisplayPrices() {
		for (auto& s : stcs) s.Info();
		cout << endl;
	}
};