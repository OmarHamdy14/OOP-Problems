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
public:
	string Symbol;
	float Price;
	Stock(string& s,float p) : Symbol(s),Price(p) {}
	void Info() {
		cout << Symbol << " " << Price << "\n";
	}
};

class Player {
public:
	string Name;
	float Balance;
	map<string, float> OwnStocks;
	Player(string& n, float b) : Name(n),Balance(b) {}
	void Buy(Stock& st, int quantity) {
		float cost = quantity * st.Price;
		if (Balance >= cost) {
			OwnStocks[st.Symbol] += quantity;
			Balance -= st.Price * quantity;
		}
		else {
			cout << Name << " does not have enough balance." << endl;
		}
	}
	void Sell(Stock& st, int quantity) {
		if (OwnStocks[st.Symbol] >= quantity) {
			Balance += st.Price * quantity;
			OwnStocks[st.Symbol] -= quantity;
		}
		else {
			cout << Name << " does not own enough shares." << endl;
		}
	}
};


class Market {
public:
	vector<Stock> stcs;
	void AddStock(string sym, float pr) {
		stcs.push_back(Stock(sym, pr));
	}
	void DisplayPrices() {
		for (auto& s : stcs) s.Info();
		cout << endl;
	}
};