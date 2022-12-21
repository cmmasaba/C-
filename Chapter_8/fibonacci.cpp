#include <iostream>
#include <vector>
using namespace std;

/**
 * main - driver function
 *
 * Return: 0 always success
 */
int main(void)
{
	try {
		size_t num1, num2, num3;
		vector<size_t> fib;
		void fibonacci(size_t, size_t, vector<size_t> &, size_t);
		void print(const vector<size_t> &);

		cout << "Enter the first number of the fibonacci sequence\n";
		cin >> num1;
		cout << "Enter the second number of the fibonacci sequence\n";
		cin >> num2;
		cout << "Enter the number of elements the fibonacci sequence"
			<< " should contain\n";
		cin >> num3;
		fibonacci(num1, num2, fib, num3);
		cout << "The fibonacci sequence is:\n";
		print(fib);
	} catch (exception &e) {
		cerr << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "Unknown exception\n";
		return 1;
	}
}


/**
 * fibonacci - generates fibonacci sequence
 * @num1: first number of sequence
 * @num2: second number of sequence
 * @num: vector to store the sequence in
 * @num3: number of elements in the sequence
 */
void fibonacci(size_t num1, size_t num2, vector<size_t> &num, size_t num3)
{
	num.push_back(num1);
	num.push_back(num2);
	for(size_t i = 2; num.size() < num3; i++)
		num.push_back(num[i-1]+num[i-2]);
}


/**
 * print - prints the elements of a vector
 * @fib: the vector tp print out
 */
void print(const vector<size_t> &fib)
{
	void error(string);
	if(fib.empty())
		error("Empty vector");
	for(size_t i=0; i < fib.size(); i++)
	{
		cout << fib[i];
		if(i < fib.size()-1)
			cout << ", ";
	}
	cout << "\n";
}

/**
 * error - throw an exception
 * @str: a message to give the user
 */
void error(string str)
{
	throw runtime_error(str);
}
