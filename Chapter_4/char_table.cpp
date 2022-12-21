#include <iostream>
using namespace std;

/**
 * main - generates the character table from a-z using while loop
 *
 * Try this exercise under chapter 4.4.2.1
 * Return: 0 always successful
 */
int main (void)
{
	char x = 'a';

	cout << "The character sequence from a-z is: \n";
	while (x <= 'z')
	{
		cout << x << "\t" << int(x) << endl;
		++x;
	}
	return (0);
}
