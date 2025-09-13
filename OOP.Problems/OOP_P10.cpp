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
public:
	string Name;
	double Price;
	int Quantity;
	Book(string& nm,double p,int q) : Name(nm),Price(p),Quantity(q) {}
	void Info() {
		cout << "Book Name: " << Name << "/n" << "Price: " << Price << endl;
	}
};
class User {
	string Name;
	vector<unique_ptr<Book>> MyBooks;
	//vector<shared_ptr<Book>> MyBooks;
	User(string& nm) : Name(nm) {}
	void BuyBook(unique_ptr<Book> b) {
		MyBooks.push_back(move(b));
	}
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
public:
	string Name;
	vector<unique_ptr<Book>> Books;
	Library(string& n) : Name(n) {}
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
			if (book->Name == title) {
				cout << "The book is found" << endl;
				return;
			}
		}
		cout << "This book is not found" << endl;
	}
};