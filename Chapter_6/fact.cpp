#include <iostream>
using namespace std;

long long int factorial(int num)
{
	if (num == 1 || num == 0)
		return (1);
	else
		return (num * factorial(num - 1));
}
int main(void)
{
	int num = 0;

	cin >> num;
	long long int result = factorial(num);
	cout << result << endl;

	return (0);
}
