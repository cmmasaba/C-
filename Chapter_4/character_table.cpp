#include <iostream>
using namespace std;

/**
 * main - generates uppercase and lowercase charaters from a-z using for loop
 *
 * Try this exercise under chapter 4.4.2.3
 * Return: 0 always successful
 */
int main (void)
{
	char x;

	cout << "The lowercase character table from a-z is: \n";
	for (x = 'a'; x <= 'z'; ++x)
		cout << x << "\t" << int(x) << endl;
	cout << "\nThe uppercase character table from A-Z is: \n";
	for (x = 'A'; x <= 'Z'; ++x)
		cout << x << "\t" << int(x) << endl;

	return (0);
}
