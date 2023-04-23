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
	bool validate(string str);
	string str;

	cout << "Enter ISBN: ";
	cin >> str;
	cout << str.size() << "\n";
	bool isbn = validate(str);
	if(isbn)
		cout << "The ISBN is " << str << "\n";
	else 
		cout << "Invalid value\n";
	return 0;
}

bool validate(string str)
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

                for(size_t i=0; i<size; i++){
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
