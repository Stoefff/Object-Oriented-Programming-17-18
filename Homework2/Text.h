#ifndef __TEXT__HEADER__
#define __TEXT__HEADER__

#include "Line.h"

class Text {
public:
	Text();
	Text(const char*);
	Text(const Text&);
	Text& operator=(const Text&);
	~Text();

	void addLine(const char* );
	void deleteLine(size_t);

	void makeHeading(size_t);
	void makeWordItallic(size_t, size_t, size_t);
	void makeWordBold(size_t, size_t, size_t);
	void makeWordCombined(size_t, size_t, size_t);

private:
	void free();
	void copy(const Text&);
	void resize();
	
	void setFilename(const char*);
	void loadTextFile();
	void saveMarkDownFile();

private:
	char* filename;
	Line * lines;
	size_t size;//number of lines
	size_t capasity;
};

#endif