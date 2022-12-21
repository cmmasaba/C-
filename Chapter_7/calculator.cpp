#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

/**
 * Simple calculator
 * This program implements a simple calculator.
 * Input is from cin; output is to cout
 * The grammar for parsing input is:
 * Calculation:
 * 	Statement
 * 	Print
 * 	Quit
 * 	Calculation statement
 * Statement:
 * 	Declaration
 * 	Expression
 * Declaration:
 * 	"let" Name = "=" Expression
 * Print:
 * 	;
 * Quit:
 * 	q
 * Expression:
 * 	Term
 * 	Expression + Term
 * 	Expression - Term
 * Term:
 * 	operators
 * 	Term * operators
 * 	Term / operators
 * 	Term % operators
 * operators:
 * 	!
 * 	Primary
 * Primary:
 * 	Number
 * 	(Expression)
 * 	- Primary
 * 	+ Primary
 * Number:
 * 	floating point literal
 *
 */

const string prompt = "> ";
const string result = "= ";
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char let = 'L';
const string declkey = "let";

/**
 * keep_window_open - called before the program terminates
 * @str: a string that the user should input in order to exit
 * the program
 *
 */
void keep_window_open(string str)
{
	string ch;

	cout << "Please enter " << str << " to exit\n";
	while (cin >> ch)
	{
		if (str == ch)
			return;
	}
}

/**
 * error - handles errors by throwing exceptions with a message
 * @s1: mandatory message to give to the user
 * @s2: the second optional message
 *
 */
void error(string s1, string s2)
{
	throw runtime_error(s1+s2);
}

/**
 * representation of a variable in the calculator program
 */
class Variable
{
	public:
		string name;
		double value;
		double get_value(string str);
		void set_value(string str, double val);
};
vector<Variable> var_table; // stores a list of variables used in the calculation

/**
 * get_value - goes through a list of variables and return the value of
 * a variable of the given name
 * @str: the name to search for in the variable list
 *
 * Return: the value associated with that name
 */
double Variable::get_value(string str)
{
	for (const Variable& v : var_table)
		if (v.name == str)
			return (v.value);
	error("get: undefined variable ", str);
}

/**
 * set_value - goes through a list of variables and assigns a value to a
 * variable of the given name
 * @str: the name to search for in the variable list
 * @val: the vallue to assign to the variable
 *
 */
void set_value(string str, double val)
{
	for (Variable& v : var_table)
		if (v.name == str)
		{
			v.value = val;
			return;
		}
	error("set: undefined variable ", str);
}

/**
 * is_declared - goes through a list of variables to see
 * if a the given variable name is declared
 * @str: the variable name to search for
 *
 * Return: true if declared, false otherwise
 */
bool is_declared(string str)
{
	for (const Variable& v : var_table)
		if (v.name == str)
			return (true);
	return (false);
}

/**
 * define_name - creates a variable of the name given to it
 * @str: the name of the new variable
 * @val: the value to assign the variable
 * 
 * Return: the value of the new variable
 */
double define_name(string str, double val)
{
	if (is_declared(str))
		error (str, " declared twice");
	var_table.push_back(Variable{str, val});
	return val;
}
 
/**
 * how a token is represented in the calculator program
 */
class Token
{
	public:
		char kind;
		double value;
		string name;
		Token(char ch) : kind {ch} {};
		Token(char ch, double val) : kind {ch}, value {val} {};
		Token(char ch, string n) : kind {ch}, name {n} {};
};

/**
 * reads and parses the input given by the user and tokenizes it
 */
class Token_stream
{
	public:
		Token_stream();
		Token get();
		void ignore(char c);
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
		error ("putback() into a full buffer", "");
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
		case print:
		case quit:
		case '(': case ')': case '+': case '-': case '*': case '/': case '{':
		case '}': case '!': case '%': case '^':
			return Token{ch};
		case '.':
		case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			{
				cin.putback(ch);
				double val;
				cin >> val;
				return Token{number, val};
				break;
			}
		default:
			if (isalpha(ch))
			{
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
					s += ch;
				if (s == declkey)
					return (Token(let));
				return (Token{name, s});
			}
			error ("Bad token", "");
	}
}

/**
 * ignore - discard all characters in the token stream until it finds the
 * specified character
 * @c: the character to look for in stream
 *
 */
void Token_stream::ignore(char c)
{
	if(full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;
	char ch = 0;
	while (cin >> ch)
	{
		if (ch == c)
			return;
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
					error ("'}' expected", "");
				return (d);
				break;
			}
		case '(':
			{
				double d = expression();
				t = ts.get();
				if (t.kind != ')')
					error ("')' expected", "");
				return (d);
				break;
			}
		case number:
			return (t.value);
			break;
		case '-':
			return -primary();
		case '+':
			return primary();
		default:
			error ("Primary expected", "");
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
			case '^':
				ans = pow(ans, primary());
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
						error ("Division by zero", "");
					lval /= d;
					t = ts.get();
					break;
				}
			case '%':
				{
					double d = operators();
					if(d == 0)
						error("Division by zero", "");
					lval = fmod(lval, d);
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
 * declaration - declares and defines a variable
 *
 * Return: the value assigned to the variable
 */
double declaration (void)
{
	Token t = ts.get();
	if (t.kind != name)
		error ("Name exprected in declarartion", "");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')
		error ("= expected in declaration of", var_name);
	double d = expression();
	define_name(var_name, d);
	return (d);
}

/**
 * statement - handles expressions and declarations
 *
 * Return: the value of the evaluated expression or declaration
 */
double statement (void)
{
	Token t = ts.get();

	switch(t.kind)
	{
		case let:
			return (declaration());
		default:
			ts.putback(t);
			return (expression());
	}
}
/**
 * clean_up_mess - flushes the token stream after an error
 *
 */
void clean_up_mess (void)
{
	ts.ignore(print);
}

/**
 * calculate - runs the calculation loop
 *
 */
void calculate(void)
{
	while (cin)
	{
		try {
			cout << prompt;
			Token t = ts.get();
			while(t.kind == print)
				t = ts.get();
			if (t.kind == quit)
				return;
			ts.putback(t);
			cout << result << statement() << endl;
		}
		catch (exception &e) {
			cout << e.what() << endl;
			clean_up_mess();
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
		// predefined names
		define_name("pi", 3.14159265358979);
		define_name("e", 2.7182818284);
		calculate();
		keep_window_open("..");
		return (0);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		keep_window_open("..");
		return (1);
	}
	catch (...) {
		cerr << "Unknown exception.\n";
		keep_window_open("..");
		return (-1);
	}
}
