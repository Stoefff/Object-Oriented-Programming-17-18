#include "Word.h"
#include <cstring>

Word::Word()
	:content(nullptr)
	, size(0)
	, position(0) {}


Word::Word(const char* content, const size_t position)
	:size(0)
	,position(position){
	size = strlen(content) + 1;
	this->content = new char[size];
	strcpy(this->content, content);
}

Word::Word(const Word& rhs) {
	copy(rhs);
}

Word& Word::operator=(const Word& rhs) {
	if (this != &rhs) {
		free();
		copy(rhs);
	}
	return *this;
}

Word::~Word() {
	free();
}

void Word::copy(const Word& rhs) {
	this->size = rhs.size;
	this->position = rhs.position;
	this->content = new char[this->size];
	strcpy(this->content, rhs.content);
}

void Word::free() {
	delete[] this->content;
	this->content = nullptr;
	this->size = 0;
	this->position = 0;
}

size_t Word::getPosition() const {
	return this->position;
}

size_t Word::getSize() const {
	return this->size;
}

void Word::setPosition(size_t pos) {
	this->position = pos;
}

void Word::setSize(size_t size) {
	this->size = size;
}