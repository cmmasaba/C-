#include <iostream>
#include <vector>
using namespace std;

/**
 * main - aprogram that converts user input which is number to its
 * corresponding string value
 * 
 * Return: 0 always success
 */
int main (void)
{
	vector<string> numbers = {"zero", "one", "two", "three", "four", "five"
	, "six", "seven", "eight", "nine", "ten"};
	int int_input = 0;
	string str_input = "";
	string answer;

	cout << "\tThis program converts an integer input to a string\n"
		<< "\tFor example an input of 1 will give an output of 'one'\n"
		<< "\tIt also converts a string input to an integer\n"
		<< "\tFor example an input of ten will give output of 10\n"
		<< "\tAnswer the questions using Yes or No\n";
	cout << "Do you wish to convert from integer to string?\n";
	cin >> answer;
	if (answer == "Yes")
	{
		cout << "Enter the integer value: ";
		cin >> int_input;
		switch(int_input)
		{
			case 0:
				cout << numbers[0] << endl;
				break;
			case 1:
				cout << numbers[1] << endl;
				break;
			case 2:
				cout << numbers[2] << endl;
				break;
			case 3:
				cout << numbers[3] << endl;
				break;
			case 4:
				cout << numbers[4] << endl;
				break;
			case 5:
				cout << numbers[5] << endl;
				break;
			case 6:
				cout << numbers[6] << endl;
				break;
			case 7:
				cout << numbers[7] << endl;
				break;
			case 8:
				cout << numbers[8] << endl;
				break;
			case 9:
				cout << numbers[9] << endl;
				break;
			case 10:
				cout << numbers[10] << endl;
				break;
			default:
				cout << "No available conversion for " <<
					int_input << endl;
		}
	}
	else
	{
		cout << "Enter the string value: ";
		cin >> str_input;
		if (str_input == numbers[0])
			cout << "0" << endl;
		else if (str_input == numbers[1])
			cout << "1" << endl;
		else if (str_input == numbers[2])
			cout << "1" << endl;
		else if (str_input == numbers[3])
			cout << "3" << endl;
		else if (str_input == numbers[4])
			cout << "4" << endl;
		else if (str_input == numbers[5])
			cout << "5" << endl;
		else if (str_input == numbers[6])
			cout << "6" << endl;
		else if (str_input == numbers[7])
			cout << "7" << endl;
		else if (str_input == numbers[8])
			cout << "8" << endl;
		else if (str_input == numbers[9])
			cout << "9" << endl;
		else if (str_input == numbers[10])
			cout << "10" << endl;
		else
			cout << "No available conversion for " <<
				str_input << endl;
	}
	return (0);
}
