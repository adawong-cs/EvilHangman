#pragma once

#include <string>
#include <set>
class Dictionary
{
public: 
	Dictionary();
	Dictionary(std::string filepath);

	void ReadFile(std::string s);
	std::set<std::string> GetWords() const;
	void AddWord(std::string s);

private:
	std::set<std::string> words;
};