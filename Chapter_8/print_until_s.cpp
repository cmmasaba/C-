#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	void read(vector<string> &, string &);
	void print_until_s(const vector<string> &, string);
	try {
		vector<string> str;
		string quit;

		read(str, quit);
		print_until_s(str, quit);
	} catch (exception &e) {
		cerr << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "Unknown exception\n";
		return 1;
	}

	return 0;
}

/**
 * read - prompts user for strings to fill the vector with
 * and also the quit message
 * @str: the vector to fill out with user strings
 * @quit: string to store the quit message in
 */
void read(vector<string> &str, string &quit)
{
	string temp, stop = "~";
	cout << "Enter the  strings" << endl;
	cout << "Type ~ to end read operation" << endl;
	while(cin>>temp)
	{
		if(temp == stop)
			break;
		str.push_back(temp);
	}
	cout << "Enter the string to use to stop writing the vector contents\n";
	cin >> quit;
	return;
}

/**
 * print_until_s - prints the contents of a vector
 * stops when it enconuters the quit message twice
 * @str: the vector to print out
 * @quit: the quit message
 */
void print_until_s(const vector<string> &str, const string quit)
{
	int counter = 0;
	int stop = 2;
	void error(string);

	if(str.empty())
		error("Empty vector");

	cout << endl;
	for(string s:str) {
		if(s==quit)
		{
			++counter;
			if(counter==stop)
				return;
			continue;
		}
		cout <<  "\t" << s << endl;
	}
}

/**
 * error - throw an error message
 * @s: the message to give the user
 */
void error(string s)
{
	throw runtime_error(s);
}

