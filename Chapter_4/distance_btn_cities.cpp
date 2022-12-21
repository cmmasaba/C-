#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * main - prompts the user to enter metric values
 * It then determines the largest and smallest values
 * The sum of the values, the number of values given
 * Finally it sorts the values and prints them in meters
 *
 * Return: 0 always success
 */
int main (void)
{
	bool flag = true;
	double smallest = 0, largest = 0, num = 0;
	double sum = 0;
	vector<double> distance;

	cout << "Enter the distance between two cities in meters.\n";
	while (cin >> num)
	{
		/* check if this is the first value being entered by
		 * the user and initialize the variables with this
		 * value. Automatically this becomes the largest value
		 * provided so far.
		 */
		if (flag == true)
		{
			largest = num;
			smallest = num;
			flag = false;
		}

		if (num > largest)
		{
			cout << " the largest so far.\n";
			largest = num;
		}
		else if (num < smallest)
		{
			cout << " the smallest so far.\n";
			smallest = num;
		}
		sum += num;
		distance.push_back(num);		
	}
	cout << "The smallest distance between 2 cities: " << smallest << endl;
	cout << "The largest distance between 2 cities: " << largest << endl;
	cout << "The mean distance between 2 cities: " << sum / distance.size()
		<< endl;
	cout << "The sum of the distances: " << sum << "m\n";
	return (0);
}
