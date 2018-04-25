#include "Line.h"
#include "HelperFuntions.h"
#include <iostream>
#include <cstring>

Line::Line()
	:content(nullptr)
	, words(nullptr)
	, size(0)
	, wordsCount(0)
{
	words = new Word[1];
	content = new char[1];
}

Line::Line(const char* content)
	:size(0){
	this->size = strlen(content) +1 ;
	this->content = new char[size];
	strcpy(this->content, content);
	populateWords();
}

Line::Line(const Line& rhs) {
	copy(rhs);
}

Line& Line::operator=(const Line& rhs) {
	if (this != &rhs) {
		free();
		copy(rhs);
	}
	return *this;
}

Line::~Line(){
	free();
}

void Line::copy(const Line& rhs) {
	this->size = rhs.size;
	this->content = new char[size];
	strcpy(this->content, rhs.content);
	populateWords();
}

void Line::free() {
	delete[] content;
	content = nullptr;
	delete[] words;
	words = nullptr;
	size = 0;
}
/*
void Line::countWords() {
	char* temp = content;
	while (*temp != '\0') {
		if ((isWhitespace(*temp) == false)
			&&(isWhitespace(*(temp + 1) == true))) { //Possible problems here
			wordsCount++;
		}
	}
}
*/
void Line::populateWords() {
	wordsCount = countWords(content);
	char* temp = content;
	this->words = new Word[wordsCount];
	size_t position = 0;
	for (int i = 0; i < wordsCount; i++) {
		char buffer[maxLineSize];
		while (isWhitespace(*temp)) {
			temp++;
			position++;
		}
		int j = 0;
		while (!isWhitespace(*temp)) {
			buffer[j] = *temp;
			j++;
			temp++;
		}
		buffer[j] = '\0';
		Word word((char*)buffer, position);
		words[i] = word;
		position += j;
	}
}

void Line::addSymbols(size_t startWord, size_t endWord, const char* symbols) {
	size += 2 * strlen(symbols);
	char* temp = new char[size];
	size_t startPos = words[startWord].getPosition();
	strncpy(temp, content, startPos);
	//strNcpy does not add '\0'
	temp[startPos] = '\0';
	strcat(temp, symbols);
	char* temp1 = content + startPos;
	size_t endPos = words[endWord].getPosition();
	//Because it should concat substring of the line
	endPos -= startPos;// We should account for the already copied symbols
	endPos += words[endWord].getSize() -1; //And add the word;
	//Docs says strNcat always adds '\0' so i will thrust this whit my life
	strncat(temp, temp1, endPos);
	strcat(temp, symbols);
	temp1 = content + words[endWord].getPosition() + words[endWord].getSize()-1;
	strcat(temp, temp1);
	delete[] content;
	content = temp;
	saveWordsChanges(startWord, endWord, strlen(symbols));
}

void Line::makeHeading() {
	size += 2;//Adding 2 new symbols
	char* temp = new char[size];
	strcpy(temp, "# ");//with '\0'
	strcat(temp, content);
	delete[] content;
	content = temp;
	for (int i = 0; i < wordsCount; i++) {
		words[i].setPosition(words[i].getPosition() + 2);
	}
}

void Line::saveWordsChanges(size_t startWord, size_t endWord, size_t symSize) {
	for (int i = startWord; i <= endWord; i++) {
		words[i].setPosition(words[i].getPosition() + symSize);
	}
	for (int i = endWord + 1; i < wordsCount; i++) {
		words[i].setPosition(words[i].getPosition() + 2*symSize);
	}
}

void Line::makeItalic(size_t startWord, size_t endWord) {
	addSymbols(startWord, endWord, "*");
}

void Line::makeBold(size_t startWord, size_t endWord) {
	addSymbols(startWord, endWord, "**");
}

void Line::makeCombined(size_t startWord, size_t endWord) {
	addSymbols(startWord, endWord, "***");
}

void Line::writeLine(std::ofstream& file) {
	file << content << '\n';
}
