#pragma once

#include <string>
#include <set>

class Hangman
{
public:
	Hangman();

	std::string GetStatus() const;
	bool InsertGuess(char guess);
	std::set<char> GetPastGuesses() const;
	void StartGame(std::set<std::string> words);
	bool IsGameOver() const;
	std::string GetWord() const;

private:
	int guessesMissed;
	std::set<char> alreadyGuessedLetters;
	std::set<std::string> possibleWords;
	int wordSize;

};
