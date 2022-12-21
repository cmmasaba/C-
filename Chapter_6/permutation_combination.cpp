#include <iostream>
using namespace std;

/**
 * error - does error handling for wrong
 * @str: a helpful message to pass to the user
 *
 */
void error (string str)
{
	throw runtime_error(str);
}

/**
 * factorial - does the factorial of a number
 * @num: the number to do factorial of
 *
 * Return: the factorial of the given number
 */
unsigned long long int factorial(int num)
{
	if (num == 1 || num == 0)
		return (1);
	return (num * factorial(num - 1));
}

/**
 * permutation - finds the permutation of two sets of numbers
 * @set: the large set
 * @subset: the smaller subset of set
 *
 * Return: the permutation of the two sets of numbers
 */
unsigned long long int permutation(int set, int subset)
{
	unsigned long long int perm_result = 0;

	if (set < subset)
                error ("The set has to be larger than subset");
        if (set < 0 || subset < 0)
                error ("Provide only positve numbers for the set and subset");
	if (subset == 0)
		perm_result = 1;
	else
		perm_result = factorial(set)/factorial(set - subset);

	return (perm_result);
}

/**
 * combination - finds the combination of two sets of numbers
 * @set: the large set
 * @subset: the smaller subset of set
 *
 * Return: the combination of the two sets of numbers
 */
unsigned long long int combination(int set, int subset)
{
	unsigned long long int com_result = 0;

	if (set < subset)
        	error ("The set has to be larger than subset");
	if (set < 0 || subset < 0)
		error ("Provide only positve numbers for the set and subset");
	if (subset == 0)
		com_result = 1;
	else
		com_result = permutation(set, subset)/factorial(subset);

	return (com_result);
}

/**
 * main - a program to find the combination of two sets
 *
 * Return: 0 always success
 */
int main(void)
{
	int set = 0, subset = 0;
	char operation;

	try {
		cout << "Enter the large set: ";
		cin >> set;
		cout << "Enter the smaller set: ";
		cin >> subset;
		cout << "Enter the operation to perform: P for permutation "
			<< "and C for combination\n";
		cin >> operation;

		switch(operation)
		{
			case 'P':
				{
					unsigned long long int result = permutation(set, subset);
					cout << "The permutation P(" << set << ", " << subset << ") is: "
                				<< result << endl;
					break;
				}
			case 'C':
				{
					unsigned long long int result = combination(set, subset);
					cout << "The combination C(" << set << ", " << subset << ") is: "
                				<< result << endl;
					break;
				}
			default:
				error ("Invalid operation, select between P and C");
		}
		
		return (0);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		return (1);
	}
	catch (...)
	{
		cout << "Unknown exception\n";
		return (1);
	}
}
