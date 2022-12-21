#include <iostream>
using namespace std;

/**
 * main - a program that converts yen, euro, kes or pound to us dollars
 *
 * Try this exercise under chapter 4.4.1.1.1
 * Return: 0 always success
 */
int main (void)
{
	constexpr double yen = 0.0067;
	constexpr double euro = 0.99;
	constexpr double pound = 1.15;
	constexpr double kes = 0.0082;
	double amount = 0, converted_amount = 0;
	string currency;

	cout << "This program does currency conversion from yen euro pound "
		<< "or kes to us dollars.\n";
	cout << "Enter the currency you want to convert e.g (1 yen): ";
	cin >> amount >> currency;
	if (currency == "yen")
	{
		converted_amount = amount * yen;
		cout << amount << " in USD is " << converted_amount << endl;
	}
	else if (currency == "euro")
	{
		converted_amount = amount * euro;
		cout << amount << " in USD is " << converted_amount << endl;
	}
	else if (currency == "pound")
	{
		converted_amount = amount * pound;
		cout << amount << " in USD is " << converted_amount << endl;
	}
	else if (currency == "kes")
	{
		converted_amount = amount * kes;
		cout << amount << " in USD is " << converted_amount << endl;
	}
	else
		cout << "Undefined currency conversion.\n";

	
	return (0);
}
