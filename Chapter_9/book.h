#ifndef BOOK_H
#define BOOK_H

#include "chrono.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

namespace Books {
	enum class Genre {
		fiction=0, nonfiction, periodical, biography, children
	};
	class Book {
	public:
		Book(string isbn, string title, string author, Chrono::Date date, Genre genre);
		Book();
        	bool check_out();
        	bool check_in();
        	string get_ISBN() const {return ISBN;}
        	string get_title() const {return book_title;}
        	string get_author() const {return book_author;}
		Chrono::Date get_copyright_date() const {return copyright_date;}
		Genre get_genre() const { return category;}
        	bool is_checkedout() const {return checkedout;}
		Chrono::Date get_borrow_date() const {return borrow_date;}
		Chrono::Date get_return_date() const {return return_date;}
	private:
		string ISBN;
        	string book_title;
        	string book_author;
		Chrono::Date copyright_date;
		Genre category;
        	bool checkedout = false;
		Chrono::Date return_date;
        	Chrono::Date borrow_date;
	};

	bool validate_ISBN(string& str);
	bool operator==(const Book& book1, const Book& book2);
	bool operator!=(const Book& book1, const Book& book2);
	bool compare(const Chrono::Date& a, const Chrono::Date& b);
	ostream& operator<<(ostream& os, const Book& book1);
	Book create_book();
}

namespace Pat {
	class Patron {
	public:
		Patron();
		Patron(string names, string number, int fee);
		string get_name() const {return name;}
		string get_number() const {return card_number;}
		int get_fees() const {return fees;}
		void set_fees(int fee);
	private:
		string name;
		string card_number;
		int fees = 0;
	};

	bool owes_fees(const Patron& person);
	bool operator==(const Patron& p1, const Patron& p2);
	ostream& operator<<(ostream& os, const Patron& person);
	Patron create_patron();
}

namespace Lib {
	class Library {
	public:
		struct Transaction {
                        Books::Book book;
                        Pat::Patron patron;
                        Chrono::Date date;
                        Transaction(Books::Book books, Pat::Patron patrons, Chrono::Date dates);
                };
		Library();
		vector<Books::Book> get_books() const {return books;}
		vector<Pat::Patron> get_patrons() const {return patrons;}
		vector<string> patron_fees() const;
		vector<Transaction> get_transactions() const {return transaction;}
		bool add_book(Books::Book book1);
		bool add_patron(Pat::Patron patron1);
		void add_transaction(Transaction t1);
		bool checkout_book(string book, string patron);
		bool checkin_book(string book, string patron);
	private:
		vector<Books::Book> books;
		vector<Pat::Patron> patrons;
		vector<Transaction> transaction;
	};
}

Chrono::Date get_date(string str);
void error(string str);
#endif
