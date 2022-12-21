#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
	try {
		vector<int> numbers;
		vector<int> reverse_numbers;
		void print(const vector<int> &);
		void read(vector<int> &);
		void reverse(vector<int> &, vector<int> &);

		read(numbers);
		cout << "Elements before reversing:" << endl;
		print(numbers);
		reverse(numbers, reverse_numbers);
		cout << "Elements after reversing:" << endl;
		print(reverse_numbers);
	} catch (exception &e) {
		cerr << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "Unknown exception" << endl;
		return 1;
	}
	return 0;
}


/**
 * read - prompts the user to enter the contents of a vector
 * @numbers: the vector to store values in
 */
void read(vector<int> &numbers)
{
	int entry = 0;
	int stop = 000;

	cout << "Enter numbers to store in the vector" << endl;
	cout << "Type 000 to end reading operation" << endl;
	while(cin>>entry)
	{
		if(entry==stop)
			break;
		numbers.push_back(entry);
	}
}


/**
 * reverse - reverse the contents of a vector
 * @numbers: the vector to reverse
 * @reverse_numbers: the vector to store reversed elements in
 *
 */
void reverse(vector<int> &numbers, vector<int> &reverse_vec)
{
	void error(string);
	vector<int>::reverse_iterator rit = numbers.rbegin();

	if(numbers.empty())
		error("Empty vector");
	for(; rit != numbers.rend(); ++rit)
		reverse_vec.push_back(*rit);
}


/**
 * error - throw an exception
 * @str: a message to give the user
 */
void error(string str)
{
	throw runtime_error(str);
}

/**
 * print - displays the contents of a vector
 * @vec: the vector to print
 */
void print(const vector<int> &vec)
{
	if(vec.empty())
		error("Empty vector");
	for(size_t i=0; i<vec.size(); i++)
		cout << vec[i] << endl;
}
