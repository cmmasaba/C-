#include "book.h"

namespace Books {
	Book::Book(string isbn, string title, string author, Chrono::Date date, Genre genre)
		:ISBN{isbn}, book_title{title}, book_author{author},
	       	copyright_date{date}, category{genre}
	{
		if(!validate_ISBN(isbn))
			error("Bad input");;
	}

	Book::Book()
	{
	}

	bool Book::check_out()
	{
		bool confirm;
		if(checkedout)
			return false;
		borrow_date = get_date("Enter date of borrowing");
		return_date = borrow_date;
		return_date.add_day(7);
		checkedout = true;
		if(checkedout)
			confirm = true;
		else
			confirm = false;
		return confirm;
	}

	bool Book::check_in()
	{
		bool confirm;
		if(!checkedout){
			cout << "What??\n";
			return false;
		}
		Chrono::Date today_date = get_date("\tEnter today's date: ");
		if(compare(today_date, return_date)) {
			cout << "\tLate returning. Standard fee charged is 50\n";
		}
		checkedout = false;
		if(checkedout)
			confirm = false;
		else
			confirm = true;
		return confirm;
	}

	//helper functions
	bool validate_ISBN(string& str)
	{
        	bool valid = true;
        	try{
                	int size = str.size();
                	if((size != 13) && (size != 16)){
                        	cout << "ISBN should either be 10 or 13 digits only\n";
                        	return false;
                	}
                	char isbn_no[size];
                	size_t trial;
                	const char* delim = "-";

                	for(int i=0; i<size; i++){
                        	isbn_no[i] = str[i];
                	}
                	isbn_no[size] = '\0';
                	char* token = strtok(isbn_no, delim);

                	while(token) {
                        	const string  str1 = token;
                        	if(str1.size()==1) {
                                	if((*token >= '0' && *token <= '9') ||
                                	(*token >= 'a' && *token <= 'z') ||
                                	(*token >= 'A' && *token <= 'Z'))
                                        	valid = true;
                                	else {
                                        	return false;
                                	}
                        	}
                        	else {
                                	const int i {stoi(str1, &trial)};
                                	valid = true;
                        	}
                        	token = strtok(nullptr, delim);
                	}
        	} catch (invalid_argument &e) {
               		return false;
        	} catch(exception &e) {
                	return false;
        	} catch(...) {
                	return false;
        	}
        	return valid;
	}

	bool operator==(const Book& book1, const Book& book2)
	{
		return (book1.get_ISBN() == book2.get_ISBN());
	}

	bool operator!=(const Book& book1, const Book& book2)
	{
		return !(book1 == book2);
	}

	bool compare(const Chrono::Date& a, const Chrono::Date& b) {return a>b;}

	ostream& operator<<(ostream& os, const Book& book1)
	{
		return os << "Book title: " << book1.get_title() << "\n"
			<< "Book author: " << book1.get_author() << "\n"
			<< "Book ISBN: " << book1.get_ISBN() << "\n";
	}

	Book create_book()
	{
		string isbn, author, title;
		int genre;
		Book b1;

		cout << "\tEnter the name of the author: ";
		getline(cin, author);
		getline(cin, author);
		cout << "\tEnter the title of the book: ";
		getline(cin, title);
		cout << "\tEnter the book ISBN: ";
                getline(cin, isbn);
		cout << "\tPick a genre from the options\n";
		cout << "\t\t1) fiction\n"
		     << "\t\t2) nonfiction\n"
		     << "\t\t3) periodical\n"
		     << "\t\t4) biography\n"
		     << "\t\t5) children\n"
		     << "\t ";
		cin >> genre;
		Chrono::Date date = get_date("\tEnter the copyright date");

		switch(genre) {
			case 1:
				b1 = {isbn, title, author, date, Genre::fiction};
				break;
			case 2:
				b1 = {isbn, title, author, date, Genre::nonfiction};
				break;
			case 3:
				b1 = {isbn, title, author, date, Genre::periodical};
				break;
			case 4:
				b1 = {isbn, title, author, date, Genre::biography};
				break;
			case 5:
				b1 = {isbn, title, author, date, Genre::children};
				break;
			default:
				error("Please select a number for a valid genre from the choices");
				break;
		}
		return b1;
	}
}
