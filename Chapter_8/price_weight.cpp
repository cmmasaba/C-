#include <iostream>
#include <vector>
using namespace std;


/**
 * main - driver function
 *
 * Return: 0 alwaays success
 */
int main(void)
{
	try {
		vector<double> price;
		vector<double> weight;
		void read(vector<double> &, vector<double> &);
		void sum(const vector<double>, const vector<double>);

		read(price, weight);
		sum(price, weight);
	} catch (exception &e) {
		cerr << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "Unknown exception" << endl;
		return 1;
	}
	return 0;
}


/**
 * read - prompts user to enter elements for two vectors
 * @price: the fisrt vector
 * @weight: the second vector
 *
 */
void read(vector<double> &price, vector<double> &weight)
{
	double entry = 0;
	double stop = 000;

	cout << "Enter the prices" << endl;
	cout << "Type 000 to end reading operation" << endl;
	while(cin>>entry)
	{
		if(entry==stop)
			break;
		price.push_back(entry);
	}
	cout << "Enter the weights" << endl;
        cout << "Type 000 to end reading operation" << endl;
        while(cin>>entry)
        {
                if(entry==stop)
                        break;
                weight.push_back(entry);
        }
}


/**
 * sum - add all elements of two vectors equal sized vectors
 * @price: the first vector containing prices
 * @weight: the second vector containing weights
 *
 */
void sum(const vector<double> price, const vector<double> weight)
{
	void error(string);
	double sum = 0;

	if(price.empty() || weight.empty())
		error("Empty vector");
	if(price.size() != weight.size())
		error("Unequal size vectors");

	for(size_t i=0; i<price.size(); i++)
		sum += price[i]*weight[i];
	cout << "The index is computed as the sum of all price[i]*weight[i] "
		<< "elements in the vectors" << endl;
	cout << "The index is " << sum << endl;
}


/**
 * error - throws an exception
 * @str: the message to give the user
 */
void error(string str)
{
	throw runtime_error(str);
}
