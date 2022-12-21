#include <iostream>
using namespace std;

namespace X {
	int var;

	void print() { cout << var << endl; }
}

namespace Y {
        int var;

        void print() { cout << var << endl; }
}

namespace Z {
        int var;

        void print() { cout << var << endl; }
}

int main(void)
{
	X::var = 7;
	X::print();

	using namespace Y;
	var = 9;
	print();
	{
	using Z::var;
	using Z::print;
	var = 11;
	print();
	}
	print();
	X::print();
}
