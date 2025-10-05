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
	string Name;
	bool IsBorrowed = false;
	time_t dueDate = 0;
public:
	Book(string& n,bool ib) : Name(n),IsBorrowed(ib) {}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
	bool GetIsBorrowed() const { return IsBorrowed; }
	void SetIsBorrowed(bool ib) { IsBorrowed = ib; }
	time_t GetdueDate() const { return dueDate; }
	void SetdueDate(time_t t) { dueDate = t; }
};
class Person {
	string Name;
	vector<unique_ptr<Book>> BorrowedBooks;
public:
	Person(string& n) : Name(n) {}
	void AddBook(unique_ptr<Book>& book) {
		BorrowedBooks.push_back(move(book));
	}
	string GetName() const { return Name; }
	void SetName(string& n) { Name = n; }
};
class Library {
	vector<unique_ptr<Book>> Books;
public:
	void AddBook(unique_ptr<Book>& book) {
		Books.push_back(move(book));
	}
};
class BorrowingManagement {
public:
	void BorrowBook(unique_ptr<Book>& book, Person& prs, int days) {
		if (book->GetIsBorrowed() == true) { cout << "Book is not availabe" << endl; return; }
		book->SetIsBorrowed(true);
		time_t now = time(0);
		book->SetdueDate(now + days * 24 * 3600);
		prs.AddBook(book);
	}
	void ReturnBook(unique_ptr<Book>& book, Library& lib) {
		if (book->GetIsBorrowed() == false) { cout << "Already Book is not borrowed" << endl; return; }
		book->SetIsBorrowed(false);
		time_t now = time(0);
		if (now > book->GetdueDate()) {
			int daysLate = (now - book->GetdueDate()) / (24 * 3600);
			double fine = daysLate * 1.0;
			cout << "(Overdue " << daysLate << " days, Fine: $" << fine << ")\n";
		}
		lib.AddBook(book);
	}
};