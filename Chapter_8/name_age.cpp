#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * main - driver function
 *
 * Return: 0 always success
 */
int main(void)
{
	try {
		vector<string> names;
		vector<int> ages;
		void read(vector<string> &, vector<int> &);
		void sort(vector<string> &, vector<int> &);
		void print(const vector<string> &, const vector<int> &);

		read(names, ages);
		cout << "Name-Age pairs before sorting:" << endl;
		print(names, ages);
		sort(names, ages);
		cout << "Name-Age pairs after sorting:" << endl;
		print(names, ages);
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
 * read - prompts the user to provide input for two vectors
 * @names: the first vector, contains names
 * @ages: the second vector, contains ages
 */
void read(vector<string> &names, vector<int> &ages)
{
	string str;
	string quit = "~";
	int num;
	int stop = 000;

	cout << "Enter the names of persons" << endl;
	cout << "Type ~ to end reading operation" << endl;
	while(cin>>str)
	{
		if(str==quit)
			break;
		names.push_back(str);
	}
	cout << "Enter the corresponding ages of the named persons" << endl;
        cout << "Type 000 to end reading operation" << endl;
        while(cin>>num)
        {
                if(num==stop)
                        break;
                ages.push_back(num);
        }
}


/**
 * sort - sorts two vectors
 * @names: first vector, contains names
 * @ages: second vector, contains ages
 */
void sort(vector<string> &names, vector<int> &ages)
{
	void error(string);
	vector<string> unsorted_names = names;
	vector<int> unsorted_ages = ages;

	if(names.empty() || ages.empty())
		error("Empty vector");
	if(names.size() != ages.size())
		error("Unequal size vectors");
	sort(names.begin(), names.end());
	ages.clear();
	for(string str1: names)
	{
		for(size_t i=0; i<unsorted_names.size(); i++)
		{
			string str2 = unsorted_names[i];
			if(str1 == str2)
			{
				ages.push_back(unsorted_ages[i]);
				unsorted_names.erase(unsorted_names.begin()+i);
				unsorted_ages.erase(unsorted_ages.begin()+i);
				break;
			}
		}
	}
}



/**
 * print - prints the contents of two vectors
 * @names: the first vector, contains names
 * @ages: the second vector, contains ages
 */
void print(const vector<string> &names, const vector<int> &ages)
{
	void error(string);
	if(names.empty() || ages.empty())
		error("Empty vector");
	if(names.size() != ages.size())
                error("Unequal size vectors");
	cout << "\t NAMES" << "\t AGES" << endl;
	for(size_t i=0; i<names.size(); i++)
		cout << "\t" << names[i] << "\t" << ages[i] << endl;
}


/**
 * error - throws an exception
 * @str: the message to give the user
 */
void error(string str)
{
	throw runtime_error(str);
}
