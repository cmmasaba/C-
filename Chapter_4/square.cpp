#include <iostream>
using namespace std;

/**
 * square - computes the square of a given number through repeated addition
 * @x: the number to compute square of
 *
 * Return: the square of the number x
 */
int square (int x)
{
	int result = 0;
	int i;

	for (i = 0; i < x; ++i)
		result += x;
	return (result);
}

/**
 * main - calculates the square of the number entered by the user
 *
 * Try this exercise under chapter 4.5.1
 * Return: 0 always success
 */
int main (void)
{
	int num = 0;
	
	cout << "Enter a number to find square of: ";
	cin >> num;
	cout << "The square of " << num  << " is " << square(num) << endl;
	return (0);
}
