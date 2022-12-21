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
	string units = "";
	vector<double> values;
	double convert_to_meters (double val, string units);

	cout << "Enter metric values. Allowed units are m, cm, in and ft.\n";
	while (cin >> num >> units)
	{
		if (units == "m" || units == "cm" || units == "in"
				|| units == "ft")
		{
			cout << num << units;
			/* standardize the user input */
			num = convert_to_meters(num, units);

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
			values.push_back(num);		
		}
		else
		{
			cout << units << endl;
			cout << "Invalid units.\n";
			continue;
		}
	}
	cout << "The smallest value in meters: " << smallest << endl;
	cout << "The largest value in meters: " << largest << endl;
	cout << "The number of values: " << values.size() << endl;
	cout << "The sum of the values: " << sum << "m\n";
	cout << "The values given in meters are as follows: \n";
	sort(values.begin(), values.end());
	for (int x : values)
	{
		cout << x << " ";
	}
	cout << endl;
	return (0);
}

/**
 * convert_to_meters - converts values to a standard unit meters
 * @val: the value to be standardized
 * @units: a string that represents the units of the value
 *
 * Return: the value in the standard form
 */
double convert_to_meters (double val, string units)
{
	double val_in_meters;
	constexpr double m_to_cm = 100.00;
	constexpr double in_to_cm = 2.54;
	constexpr double ft_to_in = 12.00;

	if (units == "cm")
	{
		val_in_meters = val / m_to_cm;
	}
	else if (units == "in")
	{
		val_in_meters = (val * in_to_cm) / m_to_cm;
	}
	else if (units == "ft")
	{
		val_in_meters = (val * ft_to_in * in_to_cm) 
			/ m_to_cm;
	}
	else
	{
		return (val);
	}

	return (val_in_meters);
}
