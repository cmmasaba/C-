#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void error(string str)
{
        throw runtime_error(str);
}

int main()
{
        bool validate(string str, char (&isbn_no)[], int size);
	bool isbn;
        string str;

        cout << "Enter ISBN: ";
        cin >> str;
	if((str.size() != 13) && (str.size() != 16)){
		cout << str.size() << "\n";
		cout << "13 or 16 only\n";
		isbn = false;
	} else {
		if(str.size() == 13){
			char check_isbn[13];
		 	isbn = validate(str, check_isbn, 13);
		} else {
			char check_isbn[16];
			isbn = validate(str, check_isbn, 16);
		}
	}
        if(isbn)
                cout << "The ISBN is " << str << "\n";
        else
                cout << "Invalid value\n";
        return 0;
}

bool validate(string str, char (&isbn_no)[], int size)
{
	bool valid = true;
	try{
		size_t trial;
                const char* delim = "-";

		for(size_t i=0; i<str.size(); i++){
                        isbn_no[i] = str[i];
                }
		isbn_no[size] = '\0';
		char* token = strtok(isbn_no, delim);

                while(token) {
			const string  str1 = token;
                        cout << str1 << " " << str1.size() << "\n";
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
                cerr << e.what() << "\n";
                return false;
        } catch(exception &e) {
                cerr << e.what() << "\n";
                return false;
        } catch(...) {
                cerr << "Unknown exception\n";
                return false;
        }
        return valid;
}
