#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {
    friend class HashTable;
 private:
	string word;
	int numAppearances;
	int totalScore;
 public:
	WordEntry(const string &, int);
    WordEntry();
	void addNewAppearance(int);
	const string & getWord();
	double getAverage();
};
#endif
