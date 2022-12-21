#include <iostream>
using namespace std;

/**
 * swap_v - swaps two int values
 * @a: the first value
 * @b: the second value
 */
void swap_v(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

/**
 * swap_r - swaps two int values
 * @a: reference to the first value
 * @b: reference to the second value
 */
void swap_r (int &a, int &b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}

/**
 * main - driver program
 *
 * Return: 0 always success
 */
int main(void)
{
	try {
		int x, y;

		x = 7;
		y = 10;
		cout << "Original values of x and y are " << x << " " << y << endl;
		swap_v(x, y);
		cout << "Swapped values, swap_v " << x << " " << y << endl;
		swap_r(x, y);
		cout << "Swapped values, swap_r " << x << " " << y << endl;
	} catch (exception &e) {
		cout << e.what() << endl;
		return (1);
	} catch (...) {
		cout << "Unknown exception.\n";
		return (2);
	}
}
