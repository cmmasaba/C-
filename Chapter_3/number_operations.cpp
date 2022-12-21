#include <iostream>
using namespace std;

/**
 * main - prompts the user to enter an operation and two operands
 * then performs the operation specified on the two operands
 *
 * Return: 0 always success
 */

int main (void)
{
	string sign;
	double operand1 = 0, operand2 = 0;

	cout << "Enter the operation followed by two operands: (i.e. + 1 2)\t";
	cin >> sign >> operand1 >> operand2;
	if (sign == "+")
		cout << "The result of " << operand1 << sign << operand2
			<< " is " << (operand1 + operand2) << endl;
	else if (sign == "-")
		cout << "The result of " << operand1 << sign << operand2
                        << " is " << (operand1 - operand2) << endl;
	else if (sign == "*")
		cout << "The result of " << operand1 << sign << operand2
                        << " is " << (operand1 * operand2) << endl;
	else if (sign == "/")
		cout << "The result of " << operand1 << sign << operand2
                        << " is " << (operand1 / operand2) << endl;
	else
		cout << "Undefined operation\n";
	return (0);
}
