#include "Dictionary.h"

#include <fstream>

Dictionary::Dictionary()
{}

Dictionary::Dictionary(std::string filepath)
{
	ReadFile(filepath);
}

void Dictionary::ReadFile(std::string filepath)
{
	std::ifstream file;
	file.open(filepath);

	while (file.good())
	{
		std::string word;
		file >> word;
		AddWord(word);
	}
}

std::set<std::string> Dictionary::GetWords() const
{
	return words;
}

void Dictionary::AddWord(std::string s)
{
	words.insert(s);
}
