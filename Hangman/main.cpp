#include <iostream>

#include "Dictionary.h"
#include "Hangman.h"

#include <time.h>

int main()
{
	// Make rand() return random numbers every run
	srand(time(0));

	using namespace std;
	Dictionary dict;

	dict.ReadFile("C:\\Users\\adapw\\Downloads\\Scrabble.txt");

	Hangman hangme;
	hangme.StartGame(dict.GetWords());

	while (!hangme.IsGameOver())
	{
		cout << hangme.GetStatus() << endl;
		char guess;
		cin >> guess;

		if (!std::isalpha(guess))
		{
			cout << "Enter a letter" << endl;
			continue;
		}

		guess = toupper(guess);

		if (!hangme.InsertGuess(guess))
		{
			cout << "You already entered this guess" << endl;
		}
	}

	cout << hangme.GetWord() << endl;
}

