#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * main - prompts the user to enter three string values and generates a sequence
 * from those strings in ascending  order
 *
 * Return: 0 always successful
 */
int main (void)
{
	string str_container[3];

	cout << "Enter three string values: (i.e str1 str2 str3) ";
	cin >> str_container[0]
	    >> str_container[1]
	    >> str_container[2];
	sort(&str_container[0], &str_container[3]);
	cout << "The string sequence is: \n" 
		<< str_container[0] << ", "
		<< str_container[1] << ", "
		<< str_container[2] << endl;
	return (0);
}
