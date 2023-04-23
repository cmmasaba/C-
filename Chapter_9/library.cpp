#include "book.h"

namespace Lib {
	Library::Library()
	{
	}
        bool Library::add_book(Books::Book book1)
        {
                books.push_back(book1);
		return true;
        }

        bool Library::add_patron(Pat::Patron patron1)
        {
                patrons.push_back(patron1);
		return true;
        }

        void Library::add_transaction(Transaction t1)
        {
                transaction.push_back(t1);
        }

	bool Library::checkin_book(string book, string patron)
	{
		bool success;
		try {
			vector<Books::Book> library_books = get_books();
                	vector<Pat::Patron> library_patrons = get_patrons();
                	bool library_book = false;
                	bool library_member = false;
                	Books::Book b1;
                	Pat::Patron p1;

			for(Books::Book book1 : library_books) {
                        	if(book == book1.get_title()) {
                                	library_book = true;
                                	b1 = book1;
                                	break;
                        	}
                	}
                	for(Pat::Patron patron1 : library_patrons) {
                        	if(patron == patron1.get_name()) {
                                	library_member = true;
                                	p1 = patron1;
                                	break;
                        	}
                	}
			if(!library_book)
                        	error("\tThe book is not available in the library.");
                	if(!library_member)
                        	error("\tThe borrower is not a member of the library patrons.");
			//if(!b1.is_checkedout())
                        //	error("\tThe book has not been checked out.");

			success = b1.check_in();
			if(success && Books::compare(b1.get_return_date(), b1.get_borrow_date()))
				p1.set_fees(50);
			else if(!success)
				return false;
		} catch (exception &e) {
			cerr << e.what() << "\n";
			return false;
		}
                return success;
	}
        bool Library::checkout_book(string book, string patron)
        {
		bool success;
		try {
                	vector<Books::Book> library_books = get_books();
                	vector<Pat::Patron> library_patrons = get_patrons();
                	bool library_book = false;
                	bool library_member = false;
                	Books::Book b1;
                	Pat::Patron p1;

                	for(Books::Book book1 : library_books) {
                        	if(book == book1.get_title()) {
                                	library_book = true;
                                	b1 = book1;
                                	break;
                        	}
                	}
                	for(Pat::Patron patron1 : library_patrons) {
                        	if(patron == patron1.get_name()) {
                                	library_member = true;
                                	p1 = patron1;
                                	break;
                        	}
                	}

                	if(!library_book)
                        	error("\tThe book is not available in the library.");
                	if(!library_member)
                	        error("\tThe borrower is not a member of the library patrons.");
                	if(Pat::owes_fees(p1))
                	        error("\tThe patron has outstanding library fees.");
			if(b1.is_checkedout())
                	        error("\tThe book has been checked out.");
			success = b1.check_out();
			if(!success)
				return false;
                	Transaction t1 {b1, p1, b1.get_borrow_date()};
                	add_transaction(t1);
		} catch (exception &e) {
			cerr << e.what() << "\n";
			return false;
		}
                return success;
        }

        vector<string> Library::patron_fees() const
        {
                vector<string> owe_fees;
                vector<Pat::Patron> library_members = get_patrons();

                for(Pat::Patron p1 : library_members) {
                        if(Pat::owes_fees(p1))
                                owe_fees.push_back(p1.get_name());
                }
                return owe_fees;
        }

        Library::Transaction::Transaction(Books::Book books, Pat::Patron patrons, Chrono::Date dates)
                :book{books}, patron{patrons}, date{dates}
        {
        }     
}
