#include "OOP_P19.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
using namespace std;

/*
* Problem Statement
Library Books
- Books can be borrowed, returned, and reserved.
- Track due dates and overdue fines.
*/
class Book {
public:
	string Name;
	bool IsBorrowed = false;
	time_t dueDate = 0;
	Book(string& n,bool ib) : Name(n),IsBorrowed(ib) {}
};
class Person {
public:
	string Name;
	vector<unique_ptr<Book>> BorrowedBooks;
	Person(string& n) : Name(n) {}
	void AddBook(unique_ptr<Book>& book) {
		BorrowedBooks.push_back(move(book));
	}
};
class Library {
public:
	vector<unique_ptr<Book>> Books;
	void AddBook(unique_ptr<Book>& book) {
		Books.push_back(move(book));
	}
};
class BorrowingManagement {
public:
	void BorrowBook(unique_ptr<Book>& book, Person& prs, int days) {
		if (book->IsBorrowed == true) { cout << "Book is not availabe" << endl; return;  }
		book->IsBorrowed = true;
		time_t now = time(0);
		book->dueDate = now + days * 24 * 3600;
		prs.AddBook(book);
	}
	void ReturnBook(unique_ptr<Book>& book, Library& lib) {
		if (book->IsBorrowed == false) { cout << "Already Book is not borrowed" << endl; return; }
		book->IsBorrowed = false;
		time_t now = time(0);
		if (now > book->dueDate) {
			int daysLate = (now - book->dueDate) / (24 * 3600);
			double fine = daysLate * 1.0;
			cout << "(Overdue " << daysLate << " days, Fine: $" << fine << ")\n";
		}
		lib.AddBook(book);
	}
};