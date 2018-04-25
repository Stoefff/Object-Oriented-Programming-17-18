#ifndef __WORD__HEADER__
#define __WORD__HEADER__

#include <iostream>

class Word {
public:
	Word();
	Word(const char*, const size_t);
	Word(const Word&);
	Word& operator=(const Word&) ;
	~Word();

	size_t getPosition() const;
	size_t getSize() const;
	void setPosition(size_t);
	void setSize(size_t);

private:
	void copy(const Word&);
	void free();

private:
	char* content;
	size_t size;
	size_t position;
};
#endif
