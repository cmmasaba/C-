#include <iostream>
#include <vector>
using namespace std;

/**
 * main - checks for prime numbers between 1 and 100
 *
 * Return: 0 always success
 */
int main (void)
{
	vector<int> primes;
	int i, max = 0;
	int isPrime (int num);

	cout << "\tThis promram finds all the prime numbers between 1 and max\n"
		<< "\tWhere max in the upper limit provided by the user\n";
	cout << "Enter the upper limit: ";
	cin >> max;
	if (max == 0)
		return (-1);
	for (i = 1; i <= max; i++)
	{
		if (isPrime(i))
			primes.push_back(i);
	}
	cout << "The prime numbers between 1-" << max << " are: \n";
	for (i = 0; i < primes.size(); i++)
	{
		cout << primes[i] << " ";
	}
	cout << endl;
	return (0);
}

/**
 * isPrime - checks if a number is prime using the primality test
 * @num: the number to be checked for primality
 *
 * Return: true is a number is prime otherwise false
 */
int isPrime (int num)
{
	int i;

	if (num == 2 || num == 3)
		return (true);
	if (num <= 1 || num % 2 == 0 || num % 3 == 0)
		return (false);
	for (i = 5; i * i <= num; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return (false);
	}
	return (true);
}
