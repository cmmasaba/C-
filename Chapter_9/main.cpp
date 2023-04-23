#include "book.h"

Chrono::Date get_date(string str)
{
	Chrono::Date date;
	try {
		int year, day, month;
                char input_date[11];
                size_t num;
                const char* delim = "/";
                const string format = " {dd/mm/yyyy}: ";
		
                cout << str << format;
                cin >> input_date;
                input_date[11] = '\0';
		{
			string d1 = input_date;
                        if(d1.size() < 10 || d1.size() > 10)
                               	error("Invalid date: use format dd/mm/yyyy");
		}
                char *token = strtok(input_date, delim);
		int i = 0;
                while(token) {
                        if(i==0) {
                        	day = {stoi(token, &num)};
                                if(day<1 || day>31)
                                	error("Invalid date: bad day");
                        } else if(i==1) {
                                month = {stoi(token, &num)};
                                if(month<1 || month>12)
                                        error("Invalid date: bad month");
                        } else
                                year = {stoi(token, &num)};
                        token = strtok(nullptr, delim);
			++i;
                }
                switch(month) {
                	case 1:
                        	date = Chrono::Date(year, Chrono::Month::jan, day);
                                break;
                        case 2:
                        	date = Chrono::Date(year, Chrono::Month::feb, day);
                                break;
                        case 3:
                        	date = Chrono::Date(year, Chrono::Month::mar, day);
                                break;
 			case 4:
                                date = Chrono::Date(year, Chrono::Month::apr, day);
				break;
                        case 5:
                        	date = Chrono::Date(year, Chrono::Month::may, day);
                                break;
                        case 6:
                                date = Chrono::Date(year, Chrono::Month::jun, day);
                                break;
                        case 7:
                        	date = Chrono::Date(year, Chrono::Month::jul, day);
                        	break;
                        case 8:
                        	date = Chrono::Date(year, Chrono::Month::aug, day);
                                break;
                        case 9:
                                date = Chrono::Date(year, Chrono::Month::sep, day);
                        	break;
                        case 10:
                        	date = Chrono::Date(year, Chrono::Month::oct, day);
                                break;
                        case 11:
                        	date = Chrono::Date(year, Chrono::Month::nov, day);
                                break;
                        case 12:
                        	date = Chrono::Date(year, Chrono::Month::dec, day);
                                break;
                }
	} catch (invalid_argument &e) {
        	error("Invalid date: use format dd/mm/yyyy");
        } catch (exception &e) {
        	cerr << e.what() << "\n";;
        } catch (...) {
                cerr << "Unknown exception\n";
        }
	return date;
}

void error(string str)
{
        throw runtime_error(str);
}

int main(void)
{
	try {
        	Lib::Library lib;
        	bool loop = true;
        	int choice;

        	while(loop) {
                	cout << "\tSelect an action from the menu \n";
                	cout << "\t1) Add book\n"
                     	     << "\t2) Add patron\n"
                     	     << "\t3) Check out book\n"
			     << "\t4) Check in book\n"
			     << "\t5) See library books\n"
			     << "\t6) See library patrons\n"
                             << "\t7) See patrons owing fees\n"
                             << "\t0) Quit\n";
			cout << "\n\t>> ";
                	cin >> choice;

                	switch(choice) {
                        	case 1:
                                {
					cout << "\tAdding book\n";
                                        Books::Book b1 = Books::create_book();
                                        if(lib.add_book(b1))
						cout << "\tBook added succesfully\n";
                                        break;
                                }
                        	case 2:
                                {
					cout << "\tAdding patron\n";
                                        Pat::Patron p1 = Pat::create_patron();
                                        if(lib.add_patron(p1))
						cout << "\tPatron added succesfully\n";
                                        break;
                                }
                        	case 3:
                                {
					cout << "\tChecking out book\n";
                                        string name, patron;
                                        cout<< "\tEnter the book name: ";
					getline(cin, name);
                                        getline(cin, name);
                                        cout << "\tEnter the name of the patron: ";
                                        cin >> patron;
                                        if(lib.checkout_book(name, patron))
						cout << "\tBook checked out succesfully\n";
					else
						cout << "\tFailed\n";
                                        break;
                                }
				case 4:
				{
					cout << "\tChecking in book\n";
                                        string name, patron;
                                        cout<<"\tEnter the book name: ";
                                        getline(cin, name);
                                        getline(cin, name);
                                        cout << "\tEnter the name of the patron: ";
                                        cin >> patron;
                                        if(lib.checkin_book(name, patron))
                                                cout << "\tBook checked in succesfully\n";
					else
						cout << "\tFailed\n";
                                        break;
				}
				case 5:
				{
					cout << "\tGeneraing list of books in library\n";
					vector<Books::Book> books = lib.get_books();
					if(books.empty()) {
						cout << "\tThere are no books in the library yet.\n";
						break;
					}
					cout << "\tBook Title \t\t Book Author\n";
					for (const Books::Book b1 : books)
						cout << "\t" << b1.get_title() <<
						     " \t\t " << b1.get_author() << "\n";
					cout << "\n\n";
					break;
				}
				case 6:
				{
					cout << "\tGenerating list of patrons in library\n";
					vector<Pat::Patron> patrons = lib.get_patrons();
					if(patrons.empty()) {
						cout << "\tThe library doesn't have patrons yet.\n";
							break;
					}
					cout << "\tPatron name \t\t Library number\n";
					for (const Pat::Patron p1: patrons)
						cout << "\t" << p1.get_name() <<
						     " \t\t " << p1.get_number() << "\n";
					cout << "\n\n";
					break;
				}
                        	case 7:
                                {
					cout << "\tGenerating list of patrons who owe fees\n";
                                        vector<string> in_debt = lib.patron_fees();
					if(in_debt.empty())
						cout << "\tThe library isn't owed any fees\n";
                                        for(string name : in_debt)
                                                cout << name << "\n";
					cout << "\n\n";
					break;
                                }
                        	case 0:
                                	loop = false;
                                	break;
                        	default:
                                	cout << "\tBad option\n";
                                	break;
                	}
		}
		return 0;
	} catch (exception &e) {
		cerr << e.what() << "\n";
		return 1;
	} catch (...) {
		cerr << "Unknown exception\n";
		return 1;
	}
}

