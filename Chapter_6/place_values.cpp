#include <iostream>
#include <string>
using namespace std;

/**
 * error - handles errors
 * @str: a message to give the user
 *
 */
void error (string str)
{
	throw runtime_error(str);
}

/**
 * place_value - determines the place values of digits passed to it
 * @str; a string of the number to find place value of
 */
void  place_value(string str)
{
	int i;
	int len = 0;
	
	for (i = 0; str[i]; i++, len++)
		;

	if (str == "")
		error("No number provided");

	cout << stoi(str) << " is ";
	for (i = 0; i < len; i++)
	{
		switch(len - i)
		{
			case 6:
				if (str[i] == '1')
					cout << str[i] - '0' << " million ";
				else
					cout << str[i] - '0' << " millions ";
				break;
			case 5:
				if (str[i] == '1')
                                        cout << str[i] - '0' << " hundred of thousand ";
                                else
                                        cout << str[i] - '0' << " hundreds of thousands ";
				break;
			case 4:
				if (str[i] == '1')
                                        cout << str[i] - '0' << " thousand ";
                                else
                                        cout << str[i] - '0' << " thousands ";
				break;
			case 3:if (str[i] == '1')
                                        cout << str[i] - '0' << " hundred ";
                                else
                                        cout << str[i] - '0' << " hundreds ";
				break;
			case 2:
				if (str[i] == '1')
                                        cout << str[i] - '0' << " ten ";
                                else
                                        cout << str[i] - '0' << " tens ";
				break;
			case 1:
				if (str[i] == '1')
                                        cout << str[i] - '0' << " one";
                                else
                                        cout << str[i] - '0' << " ones ";
				break;
			default:
				cout << "Out of bounds\n";
				break;
		}
	}
	cout << endl;
}


/**
 * main - a program to find the place values of integer digits
 *
 * Return: 0 always success
 */
int main(void)
{
	string str = "";

	try {
		cout << "Enter an integer: ";
		cin >> str;
		place_value(str);
		return (0);
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return (1);
	}
	catch (...) {
		cout << "Unknown exception" << endl;
		return (1);
	}
}
