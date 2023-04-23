#include "book.h"

namespace Pat {
        Patron::Patron(string names, string number, int fee)
                :name{names}, card_number{number}, fees{fee}
        {
                if(fee<0)
                        error("Fee cannot be less than 0");
        }
	Patron::Patron()
	{
	}

        void Patron::set_fees(int fee)
        {
                if((fees + fee) < 0)
                        error("Fee cannot be less than 0");
                fees += fee;
        }

        bool owes_fees(const Patron& person)
        {
                return (person.get_fees() != 0);
        }

        bool operator==(const Patron& p1, const Patron& p2)
        {
                return (p1.get_number()==p2.get_number()
                                && p1.get_name()==p2.get_name());
        }

        bool operator!=(const Patron& p1, const Patron& p2)
        {
                return !(p1 == p2);
        }

        ostream& operator<<(ostream& os, const Patron& person)
        {
                return os << "Patron's name: " << person.get_name() << "\n"
                        << "Patron's library card number: "
                        << person.get_number() << "\n";
        }
	Patron create_patron()
        {
                string name, number;

                cout << "\tEnter the name of the patron: ";
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, name);
                getline(cin, name);
                cout << "\tEnter the library number: ";
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, number);

                Patron p1 {name, number, 0};
                return p1;
        }
}
