#include <iostream>
using namespace std;

/**
 * main - a programm to est if a number is odd or even
 *
 * Return: 0 always success
 */

int main (void)
{
	int num = 0;

	cout << "Enter a number: ";
	cin >> num;

	if (num % 2 == 0)
		cout << "The number " << num << " is even.\n";
	else
		cout << "The number " << num << " is odd.\n";

	return (0);
}
