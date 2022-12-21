#include <iostream>
#include <vector>
using namespace std;

/**
 * error - handles errors by throwing exceptions with a message
 * @s: the message to give to the user
 *
 */
void error(string s)
{
	throw runtime_error(s);
}

class Token
{
	public:
		char kind;
		double value;
};

class Token_stream
{
	public:
		Token get();
		void putback(Token t);
	private:
		bool full{false};
		Token buffer;
};

/**
 * putback - member function of Token_stream
 * stores the read but unused tokens for use by the next calling function
 * @t: the token to be stored in buffer
 *
 */
void Token_stream::putback (Token t)
{
	if (full)
		error ("putback() into a full buffer");
	buffer = t;
	full = true;
}

/**
 * get - member function of Token_stream
 * reads a token from standard input
 *
 * Return: an object of type Token
 */
Token Token_stream::get()
{
	char ch;

	if (full)
	{
		full = false;
		return (buffer);
	}
	cin >> ch;
	switch (ch)
	{
		case ';':
		case 'q':
		case '(': case ')': case '+': case '-': case '*': case '/': case '{':
		case '}': case '!':
			return Token{ch};
		case '.':
		case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			{
				cin.putback(ch);
				double val;
				cin >> val;
				return Token{'8', val};
				break;
			}
		default:
			error ("Bad token");
	}
}

Token_stream ts;
double expression();

/**
 * primary - deals with primaries
 * this includes floating point literals and expressions starting with (
 *
 * Return: a number or an evaluated expression
 */
double primary()
{
	Token t = ts.get();
	switch(t.kind)
	{
		case '{':
			{
				double d = expression();
				t = ts.get();
				if (t.kind != '}')
					error ("'}' expected");
				return (d);
				break;
			}
		case '(':
			{
				double d = expression();
				t = ts.get();
				if (t.kind != ')')
					error ("')' expected");
				return (d);
				break;
			}
		case '8':
			return (t.value);
			break;
		case 'q':
			exit(0);
		default:
			error ("Primary expected");
	}
}

/**
 * factorial - does the factorial of a number
 * @num: the number to do factorial of
 *
 * Return: the factorial of a number
 */
int factorial (int num)
{
	if (num == 0 || num == 1)
		return 1;
	return (num * factorial(num - 1));
}

/**
 * operators - performs common arithmetic operations
 * supported operations include factorial
 *
 * Return: the result of the operation
 */
double operators()
{
	double ans =  primary();
	Token t = ts.get();

	while (true)
	{
		switch(t.kind)
		{
			case '!':
				ans = factorial((int)ans);
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return (ans);
		}
	}
}

/**
 * term - deals with terms
 * operations performed on terms include *, /
 *
 * Return: a result of the evaluated term
 */
double term()
{
	double lval = operators();
	Token t = ts.get();

	while (true)
	{
		switch(t.kind)
		{
			case '*':
				lval *= operators();
				t = ts.get();
				break;
			case '/':
				{
					double d = operators();
					if (d == 0)
						error ("Division by zero\n");
					lval /= d;
					t = ts.get();
					break;
				}
			default:
				ts.putback(t);
				return (lval);
		}
	}
}

/**
 * expression - deals with expressions
 * operatons performed on expressions include + and -
 *
 * Return: a result of the evaluated expression
 */
double expression()
{
	double lval = term();
	Token t = ts.get();
	while (true)
	{
		switch(t.kind)
		{
			case '+':
				lval += term();
				t = ts.get();
				break;
			case '-':
				lval -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return (lval);
		}
	}
}

/**
 * main - a calculator program
 * performs arithmetic on input given by the user
 *
 * Return: 0 always success
 */
int main (void)
{
	try {
		system("clear");
		double val = 0;
		while (cin)
		{
			Token t = ts.get();
			if (t.kind == 'q')
				break;
			if (t.kind == ';')
				cout << "= " << val << endl;
			else
				ts.putback(t);
			val = expression();
		}
		getc(stdin);
		return (0);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		getc(stdin);
		return (1);
	}
	catch (...) {
		cerr << "Unknown exception.\n";
		getc(stdin);
		return (-1);
	}
}
