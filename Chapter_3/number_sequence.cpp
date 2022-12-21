#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * main - a program that prompts the user to enter a number and generate a
 * sequence from the numbers based on ascending order
 *
 * Return: 0 always success
 */
int main (void)
{
	int num = 0, len = 0;
	vector<int> num_arr;

	cout << "Enter an integer number: ";
	cin >> num;

	/* convert the integer given to a vector */
	while (num)
	{
		num_arr.push_back(num % 10);
		num = num / 10;
	}
	/* sort the vector in ascending order */
	sort(num_arr.begin(), num_arr.end());
	cout << "The number sequence is: " << endl;
	for (int i : num_arr)
	{
		cout << i;
		/* insert a comma and space between the numbers */
		if (len + 1 < num_arr.size())
		{
			cout << ", ";
			++len;
		}
	}
	cout << "\n";

	return (0);
}
