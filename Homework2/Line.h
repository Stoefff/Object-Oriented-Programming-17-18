#ifndef __LINE__HEADER__
#define __LINE__HEADER__

#include "Word.h"
#include <fstream>

const size_t maxLineSize = 1024; // without '\0'

class Line{
public:
	Line();
	Line(const char*);
	Line(const Line&);
	Line& operator=(const Line&);
	~Line();

	void makeHeading();
	void makeItalic(size_t, size_t);
	void makeBold(size_t, size_t);
	void makeCombined(size_t, size_t);

	void writeLine(std::ofstream&);

private:
	void populateWords();
	void addSymbols(size_t, size_t, const char*);
	void copy(const Line&);
	void free();
	void saveWordsChanges(size_t, size_t, size_t);

private:
	char* content;
	Word* words;
	size_t size;
	size_t wordsCount;
};

#endif