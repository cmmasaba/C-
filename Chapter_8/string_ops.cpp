#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	try {
		vector<string> str;
		void init(vector<string> &);
		vector<int> str_length;
		vector<int> length(vector<string> str);
		int shortest(vector<int>);
		int longest(vector<int>);
		string lexical_order(vector<string>, int flag);
		int index;

		init(str);
		str_length = length(str);
		index = shortest(str_length);
		cout << "Shortest string " << str[index] << endl;
		index = longest(str_length);
		cout << "Longest string " << str[index] << endl;
		cout << "The first string is " << lexical_order(str, 0) << endl;
		cout << "The last string is " << lexical_order(str, 1) << endl;
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
 * init - propmts user for input
 * @str: the vector where the user input is stored
 *
 */
void init(vector<string> &str)
{
        string entry;
        const string quit = "~";

	cout << "Enter the strings.\n";
        cout << "Type ~ to terminate the reading operation.\n";
        while(cin>>entry)
        {
                if (entry == quit)
                        break;
                str.push_back(entry);
        }
}

/**
 * length - creates a vector of string lengths from a corresponding vector of strings
 * @str: the vector of strings
 *
 * Return: a vector of string sizes
 */
vector<int> length(vector<string> str)
{
	void error(string);
	vector<int> size;

	if(str.empty())
		error("Empty vector");
	for(size_t i=0; i<str.size(); i++)
	{
		string temp = str[i];
		int j = 0;
		for(; temp[j] != '\0'; j++);
		size.push_back(j);
	}
	return size;
}

/**
 * shortest - finds the shortest string in a vector of strings
 * @str_len: a vector containing the sizes of strings
 *
 * Return: the index of the shortest string
 */
int shortest(vector<int> str_len)
{
	vector<int> temp = str_len;
	int i = 0;

	sort(str_len.begin(), str_len.end());
	for(; str_len[0] != temp[i]; i++);

	return i;
}

/**
 * longest - finds the longest string in a vector of strings
 * @str_len: a vector containing sizes of strings
 *
 * Return: the index of the longest string
 */
int longest(vector<int> str_len)
{
	vector<int> temp = str_len;
        int i = 0;

        sort(str_len.begin(), str_len.end());
	int j = str_len.size() - 1;
        for(; str_len[j] != temp[i]; i++);
	
	return i;
}

/**
 * lexical_order - sorts a vector of strings
 * @str: the vector of strings
 * @flag: indicates if to return the first or last value
 *
 * Return: the first or last string
 */
string lexical_order(vector<string> str, int flag)
{
	void error(string);
	if(str.empty())
		error("Empty string");
	sort(str.begin(), str.end());

	if(flag == 0)
		return str[0];
	int i = str.size() - 1;
	return str[i];
}

/**
 * error - handles errors
 * @str: a message to give the user
 *
 */
void error (string str)
{
        throw runtime_error(str);
}

