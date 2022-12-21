#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * main - a program that tries to guess the number picked by the user.
 * the number can be between 1 to 100
 * the program shouldn't ask more than 7 questions
 * I used a binary search for this
 *
 * Return: 0 always success
 */
int main (void)
{
	int low, high, i, mid;
	vector<int> guess;
	char answer;

	cout << "Answer the questions using y for Yes and n for No:\n";
	for (i  = 1; i <= 100; i++)
	{
		guess.push_back(i);
	}
	sort(guess.begin(), guess.end());
	low = 1;
	high = guess.size();
	while ( low <= high)
	{
		mid = low + (high - low)/2;
		cout << "Is the number you're thinking of " << guess[mid]
			<< endl;
		cin >> answer;
		if (answer == 'y')
			break;
		else
		{
			cout << "Is the number less than " << guess[mid] << endl;
			cin >> answer;
			if (answer == 'y')
				high = mid - 1;
			else
				low = mid + 1;
		}
	}

	cout << "The number you're thinking of is " << guess[mid] << endl;

	return (0);
}
