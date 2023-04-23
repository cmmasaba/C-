#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Name_Age -  a class that represents name and age pairs
 */
class Name_pair {
public:
	void read_names();
	void read_ages();
	//void print();
	void sort_pair();
	vector<string> get_name() const { return name;}
	vector<double> get_age() const { return age;}
private:
	static constexpr double min_age = 0.1, max_age = 150;
	vector<string> name;
	vector<double> age;
};

/**
 * read_names - prompts user for names
 * member function of Name_pair class
 */
void Name_pair::read_names(void)
{
	string entry;
	const string stop = "~~";
	bool read = true;

	cout << "Enter the names.\n";
	cout << "Type ~~ to stop.\n";
	while(read) {
		cout << "> ";
		cin>>entry;
		if(entry==stop) {
			read = false;
			continue;
		}
		name.push_back(entry);
	}
}

/**
 * read_ages - prompts user for age values
 * member function of Name_pair class
 */
void Name_pair::read_ages(void)
{
	void error(string);
	double entry = 0;
	double stop = -1;
	bool read = true;

	cout << "Enter the ages corresponding to the names\n";
	cout << "Type -1 to stop.\n";
	while(read) {
		cout << "> ";
		cin>>entry;
		if(entry==stop) {
			read = false;
			continue;
		}
		else if(entry<min_age || entry>max_age)
			error("Invalid age");
	
		age.push_back(entry);
	}
}

/*
void Name_pair::print(void)
{
	void error(string);
	if(name.empty() || age.empty())
		error("Empty vector");
	if(name.size() != age.size())
		error("Unequal size vectors");

	cout << "\t\tNAMES   \t\t\tAGES\n";
	for(size_t i=0; i<name.size(); i++)
		cout << "\t\t" << name[i] << "\t\t\t\t" << age[i] << "\n";
}*/

/**
 * sort_pair - sorts the name and age vectors
 * member function of the Name_pair class
 */
void Name_pair::sort_pair(void)
{
	void error(string);
	bool check_size(const vector<string>& name, const vector<double>& age);
	bool check_empty(const vector<string>& name, const vector<double>& age);
	vector<string> names_copy = name;
	vector<double> ages_copy = age;

	bool valid_size = check_size(names_copy, ages_copy);
	bool is_empty = check_empty(names_copy, ages_copy);
	if(!is_empty)
		error("Empty vector");
	if(!valid_size)
		error("Unequal size vectors");

	age.clear();
	sort(name.begin(), name.end());
	for(string str: name) {
		for(size_t i = 0; i<names_copy.size(); i++) {
			if(str==names_copy[i]) {
				age.push_back(ages_copy[i]);
				ages_copy.erase(ages_copy.begin()+i);
				names_copy.erase(names_copy.begin()+i);
				break;
			}
		}
	}
}

/**
 * check_size - checks if two vectors are equal in size
 * @name: first vector
 * @age: second  vector
 *
 * Return: true if equal in size, otherwise empty
 */
bool check_size(const vector<string>& name, const vector<double>& age)
{
	bool valid_size = true;
	if(name.size() != age.size()) {
                valid_size = false;
		return valid_size;
	}
        return valid_size;
}

/**
 * check_empty - checks if a vector is empty
 * @name: first vector
 * @age: second vector
 *
 * Return: false if empty, otherwise true
 */
bool check_empty(const vector<string>& name, const vector<double>& age)
{
	bool empty = true;
	if(name.empty() || age.empty()) {
                empty = false;
                return empty;
        }
	return empty;
}

/**
 * << - operator overload to print elements
 * @os: the output stream to use
 * @pair: a user defined type to use
 *
 * Return: the output
 */
ostream& operator<<(ostream& os, const Name_pair& pair)
{
        vector<string> names = pair.get_name();
        vector<double> ages = pair.get_age();
        os << "\t\tNAMES \t\t\t\tAGES\n";
        for(size_t i=0; i<names.size(); i++)
                os << "\t\t" << names[i] << "\t\t\t\t" << ages[i] << "\n";
        return os;
}

/**
 * == - operator overload to check equality
 * @pair1: object of type Name_pair
 * @pair2: object of type Name_pair
 *
 * Return: true if equal, otherwise false
 */
bool operator==(const Name_pair& pair1, const Name_pair& pair2)
{
	vector<string> names1 = pair1.get_name();
	vector<string> names2 = pair2.get_name();
	vector<double> ages1 = pair1.get_age();
	vector<double> ages2 = pair2.get_age();
	bool equal = true;

	if(check_size(names1, ages1) && check_empty(names1, ages1)
		&& check_size(names2, ages2) && check_empty(names2, ages2)
		&& names1.size() == names2.size()) {
		for(size_t i=0; i<names1.size(); i++) {
			if((names1[i] != names2[i]) || (ages1[i] != ages2[i])) {
				equal = false;
				continue;
			}
		}
	}
	return equal;
}

/**
 * != - operator overload to check unequality
 * @pair1: object of type Name_pair
 * @pair2: object of type Name_pair
 *
 * Return: true if unequal, otherwise false
 */
bool operator!=(const Name_pair& pair1, const Name_pair& pair2)
{
	return !(pair1==pair2);
}
/**
 * error - throws exception
 * @str: the message to give the user
 */
void error(string str)
{
	throw runtime_error(str);
}

/**
 * main - driver function
 *
 * Return: 0 always success
 */
int main(void)
{
	try {
		Name_pair pairs;
		pairs.read_names();
		pairs.read_ages();
		cout << "\t\tUnsorted name-age pairs\n";
		cout << pairs;
		//pairs.print();
		pairs.sort_pair();
		cout << "\n\t\tSorted name-age pairs\n";
		cout << pairs;
		//pairs.print();
		Name_pair pair1;
		pair1.read_names();
		pair1.read_ages();
		cout << "\t\tUnsorted name-age pairs\n";
                cout << pair1;
		pairs.sort_pair();
                cout << "\n\t\tSorted name-age pairs\n";
                cout << pair1;
		if(pairs==pair1)
			cout << "The name-age pairs are equal\n";
		else
			cout << "The name-age pairs are unequal\n";
	} catch (exception &e) {
		cerr << e.what() << "\n";
		return 1;
	} catch (...) {
		cerr << "Unknown exception.\n";
		return 1;
	}
	return 0;
}
