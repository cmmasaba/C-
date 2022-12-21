#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * numbers_t - stores info about a vector of integers
 * @largest: the largest element in the vector
 * @smallest: the smallest element in the vector
 * @median: the median of the elements in the vector
 * @mean: the mean of the elements in the vector
 */
struct numbers_t {
        int largest;
        int smallest;
        int median;
	int mean;
};

/**
 * main - driver function
 * 
 * Return: 0 always success
 */
int main(void)
{
	try {
		vector<int> numbers;
		numbers_t sort(vector<int>);
		void read(vector<int> &);

		read(numbers);
		numbers_t results = sort(numbers);
		cout << "The largest number is " << results.largest << endl;
		cout << "The smallest number is " << results.smallest << endl;
		cout << "The median is " << results.median << endl;
		cout << "The mean is " << results.mean << endl;
	} catch (exception &e) {
		cerr << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "Unknown exceptions\n";
		return 1;
	}

	return 0;
}

/**
 * read - prompt the user to enter values into a vector
 * @numbers: the vector to store values in
 *
 */
void read(vector<int> &numbers)
{
	int num = 0;
	int stop = 000;

	cout << "Enter a integer values" << endl;
	cout << "Type ~ to end reading operation" << endl;

	while(cin>>num) {
		if(num == stop)
			break;
		numbers.push_back(num);
	}
}

/**
 * sort - finds the smallest, largest, median and mean of a vector of ints
 * @numbers: the vector of integers
 *
 * Return: a struct containging the smallest, largest, mean and median
 */
numbers_t sort(vector<int> numbers)
{
	void error(string);
	numbers_t temp;
	int sum = 0;

	if(numbers.empty())
		error("Empty vector");
	sort(numbers.begin(), numbers.end());
	int index = numbers.size() - 1;
	temp.largest = numbers[index];
	temp.smallest = numbers[0];

	if(numbers.size()/2 == 0)
	{
		index = numbers.size()/2;
		temp.median = (numbers[index] + numbers[index-1])/2;
	} else {
		index = numbers.size()/2;
		temp.median = numbers[index];
	}

	for(int i:numbers)
		sum += numbers[i];
	temp.mean = sum/numbers.size();

	return temp;
}

/**
 * error - throws an exception
 * @str: the error message to give the user
 *
 */
void error(string str)
{
	throw runtime_error(str);
}
