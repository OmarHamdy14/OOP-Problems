#include "OOP_P10.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
* Problem Statement
Design a digital library where content can be checked out, returned, and searched. Users can interact with content, 
and the system should track availability and ownership history.
*/
class Book {
	string Name;
	double Price;
	int Quantity;
public:
	Book(string& nm,double p,int q) : Name(nm),Price(p),Quantity(q) {}
	void Info() {
		cout << "Book Name: " << Name << "/n" << "Price: " << Price << endl;
	}
	string GetName() const { return Name; }
	double GetPrice() const { return Price; }
	int GetQuantity() const { return Price; }
	void SetQuantity(int q) { Quantity = q; }
	void SetName(string& s)  { Name = s; }
	void SetPrice(double pr) { Price = pr; }
};
class User {
	string Name;
public:
	vector<unique_ptr<Book>> MyBooks;
	//vector<shared_ptr<Book>> MyBooks;
	User(string& nm) : Name(nm) {}
	void BuyBook(unique_ptr<Book> b) {
		MyBooks.push_back(move(b));
	}
	string GetName() const { return Name; }
	void SetName(string& s) { Name = s; }
	/*void BorrowBook(shared_ptr<Book> b) {
		if (b->Quantity > 0) {
			b->Quantity--;
			//MyBooks.push_back(b);
		}
		cout << "This book is not found" << endl;
	}*/
	/*void ReturnBookToLibrary(shared_ptr<Book> b) {
		b->Quantity++;
	}*/
};
class Library {
	string Name;
public:
	vector<unique_ptr<Book>> Books;
	Library(string& n) : Name(n) {}
	string GetName() const { return Name; }
	void SetName(string& s) { Name = s; }

	void AddOrReturnBook(unique_ptr<Book> b) {
		Books.push_back(move(b));
	}
	void DisplayAllBooks() {
		for (auto& b : Books) { // is this will make error as it may make a copy of unique_ptr pointer ? ==========
			b->Info();
		}
	}
	void Search(string& title) {
		for (auto& book : Books) { // is this will make error as it may make a copy of unique_ptr pointer ? ==========
			if (book->GetName() == title) {
				cout << "The book is found" << endl;
				return;
			}
		}
		cout << "This book is not found" << endl;
	}
};