#include <iostream>
using namespace std;

/**
 * main - a program that functions as a simple calculator
 * the operations it performs include +, -, *, /
 *
 * Return: 0 always success
 */
int main (void)
{
	double operand1 = 0, operand2 = 0, result = 0;
	string operation = "";

	cout << "\tWelcome to simple calculator\n"
		<< "\tEnter two operands followed by an operation to perform\n"
		<< "\tFor example: 10 20 + to do addition of 10 and 20\n"
		<< "\tAllowed operations are +, -, *, /\n"
		<< "\tEnter your input at the prompt below:\n";
	cin >> operand1 >> operand2 >> operation;
	if (operation == "+")
	{
		result = operand1+operand2;
		cout << "The sum of " << operand1 << " and " << operand2 << " is "
			<< result << endl;
	}
	else if (operation == "-")
	{
		result = operand1-operand2;
		cout << "The difference of " << operand1 << " and " << operand2 << " is "
                        << result << endl;
	}
	else if (operation == "*")
	{
		result = operand1*operand2;
		cout << "The product of " << operand1 << " and " << operand2 << " is "
                        << result << endl;
	}
	else
	{
		result = operand1/operand2;
		cout << "The quotient of " << operand1 << " and " << operand2 << " is "
                        << result << endl;
	}
	return (0);
}
