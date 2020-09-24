#include "Hangman.h"

#include <vector>
#include <map>


Hangman::Hangman()
{
	guessesMissed = 0;
	wordSize = 0;
}


void Hangman::StartGame(std::set<std::string> words)
{
	wordSize = rand() % 7 + 4;
	guessesMissed = 0;

	for (std::string word : words)
	{
		if (wordSize == word.size())
		{
			possibleWords.insert(word);
		}
	}
}

std::set<char> Hangman::GetPastGuesses() const
{
	return alreadyGuessedLetters;
}


std::vector<int> GetPositions(std::string word, char guess)
{
	std::vector<int> v;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == guess)
		{
			v.push_back(i);
		}
	}

	return v;
}

bool Hangman::InsertGuess(char guess)
{
	using namespace std;

	if (alreadyGuessedLetters.count(guess))
	{
		return false;
	}

	map<vector<int>, set<string>> wordsPerGroup;

	for (string word : possibleWords)
	{
		wordsPerGroup[GetPositions(word, guess)].insert(word);
	}

	int value = -1;
	vector<int> biggestGroup;
	for (const auto& p : wordsPerGroup)
	{
		int groupSize = p.second.size();
		if (groupSize > value)
		{
			value = p.second.size();
			biggestGroup = p.first;
		}
	}

	if (biggestGroup.empty())
	{
		guessesMissed++;
	}

	possibleWords = wordsPerGroup[biggestGroup];
	alreadyGuessedLetters.insert(guess);

	return true;
}

std::string Hangman::GetStatus() const
{
	std::string word = *possibleWords.begin();

	std::string str = "";
	for (int i = 0; i < word.size(); i++)
	{
		if (alreadyGuessedLetters.count(word[i]))
		{
			str += word[i];
		}
		else
		{
			str += "_";
		}
	}

	return str;
}

bool Hangman::IsGameOver() const
{
	if (guessesMissed >= 12)
	{
		return true;
	}

	std::string status = GetStatus();
	if (status.find_first_of('_') == -1)
	{
		return true;
	}

	return false;
}

std::string Hangman::GetWord() const
{
	if (!IsGameOver())
	{
		return "";
	}

	return *possibleWords.begin();
}



