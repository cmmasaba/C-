#include <iostream>
#include <vector>
#include <random>
using namespace std;


/**
 * main - driver function
 *
 * Return: 0 always success
 */
int main(void)
{
	try {
		void intro();
		bool menu(void);
		void play();
		bool playing = true;

		intro();
		while(playing){
			play();
			bool keep_playing = menu();
			if(!keep_playing){
				cout << "Thanks for playing\n";
				playing = false;
			}
		}
	} catch (exception &e) {
		cerr << e.what() << "\n";
		return 1;
	} catch (...) {
		cerr << "Unknown exception\n";
		return 1;
	}
	return 0;
}

/**
 * error - throws an exception
 * @str: a message to give the user
 */
void error(string str)
{
	throw runtime_error(str);
}

/**
 * play - starts the game
 *
 */
void play(void)
{
	vector<int> answer(4);
	vector<int> guess(4);
	void generate_answer(vector<int> &);
	void get_input(vector<int> &);
	bool compare(const vector<int> &, const vector<int> &);
	bool keep_playing = true;

	generate_answer(answer);
	while(keep_playing) {
		get_input(guess);
		bool result = compare(answer, guess);
		if(result)
			keep_playing = false;
	}
}

/**
 * generate_answer - creates four random integers between 0 and 9
 * @vec: the vector to fill with the four numbers
 */
void generate_answer(vector<int> &vec)
{
	vec.clear();
	bool add = true;
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> distribution(0, 9);

	for(int i=0; vec.size()<4; i++)
	{
		int random = distribution(rng);
		for(int j = 0; j<i; j++){
			if(random == vec[j]) {
				add = false;
				continue;
			}
		}
		if(add)
			vec.push_back(random);
		add = true;
	}
}

/**
 * get_input - asks the user for their guess of the number
 * @vec: the number to store their guess in
 */
void get_input(vector<int> &vec)
{
	try {
		int answer;

		cout << "Enter your guess:  ";
		cin >> answer;

		for(int i=3; answer>0, i>=0; i--)
		{
			vec[i] = answer%10;
			answer = answer/10;
		}
	} catch (exception &e) {
		cerr << e.what() << "\n";
		return;
	}
}

/**
 * compare - finds how many digits in the user's guess match the actual value
 * @answer: the target numbers
 * @guess: the user's guess
 *
 * bulls occur when the user guesses one of the numbers in the target vector
 * and at the correct position too
 * cows occur when the user guesses one of the numbers in the target vector
 * but at the wrong position
 * the game is over when the user guesses all numbers correctly and at the
 * correct position.
 */ 
bool compare(const vector<int> &answer, const vector<int> &guess)
{
	int bulls = 0, cows = 0;

	if(answer.size() != guess.size())
		error("Unequal vector sizes");
	for(size_t i=0; i<answer.size(); i++){
		for(size_t j=0; j<guess.size(); j++){
			if(i == j && answer[i] == guess[i])
				bulls++;
			else
				if(answer[i] == guess[j])
					cows++;
		}
	}
	if(bulls == 1)
		cout << bulls << " bull ";
	else
		cout << bulls << " bulls ";
	if(cows == 1)
		cout << "and " << cows << " cow" << "\n";
	else
		cout << "and " << cows << " cows" << "\n";

	if(bulls == 4)
		return true;
	else
		return false;
}

/**
 * intro - displays an introductory message
 */
void intro(void)
{
	cout << "\t\t\t\tBULLS AND COWS\n";
	cout << "\tThe computer picks 4 random numbers in a certain order at the start of each game\n";
	cout << "\tThe player(you) tries guessing these numbers and in the correct order as the computer\n";
	cout << "\tA comparison of your guess and the correct number is made\n";
	cout << "\tIf you guess a number the computer guessed and at the same position as the computer\n";
	cout << "\tplaced it, that's a bull\n";
	cout << "\tIf you guess a number the computer guessed, but at the wrong position, that's a cow\n";
	cout << "\tThe game is over when you get 4 bulls\n";
}

/**
 * menu - displays a menu
 */
bool menu(void)
{
	bool clean_up_mess(void);
	try {	
		int response = 0;

		cout << "Please select from menu\n";
        	cout << "\t1. New game\n";
        	cout << "\t2. End\n";
		cin >> response;
		if(response == 1)
			return true;
		else if(response == 2)
			return false;
		else
			error("Bad choice");
	} catch (exception &e) {
		cerr << e.what() << "\n";
		bool response = clean_up_mess();
		if(response)
			return true;
		else
			return false;
	}
}

/**
 * clean_up_mess - takes care of incorrect input
 */
bool clean_up_mess(void)
{
	bool answer = menu();
	return answer;
}
