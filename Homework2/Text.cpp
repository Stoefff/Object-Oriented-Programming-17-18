#include "Text.h"
#include <fstream>
#include <iostream>
#include <cstring>

static const size_t initialCapasity = 1;

Text::Text()
	:filename(nullptr)
	,lines(nullptr)
	,size(0)
	,capasity(initialCapasity){
	lines = new Line[capasity];
}

Text::Text(const char* filename)
	:filename(nullptr)
	, lines(nullptr)
	, size(0)
	, capasity(initialCapasity)
{
	setFilename(filename);
	lines = new Line[capasity];
	loadTextFile();
}

Text::Text(const Text& rhs)
	:filename(nullptr)
	,lines(nullptr){
	copy(rhs);
}

Text& Text::operator=(const Text& rhs) {
	if (this != &rhs) {
		free();
		copy(rhs);
	}
	return *this;
}

Text::~Text() {
	saveMarkDownFile();
	free();
}

void Text::addLine(const char* str) {
	Line line(str);
	if (size >= capasity) {
		resize();
	}
	lines[size] = line; //
	size++;
}

void Text::deleteLine(size_t number) {
	if (size <= number) {
		std::cerr << "No such line present!";
			return;
	}
	if (size == 1) {
		size--;
	} else {
		for (int i = number; i < size -1; i++) {
			lines[i] = lines[i + 1];
		}
		size--;
	}

}

void Text::makeHeading(size_t line) {
	if (size <= line) {
		std::cerr << "No such line present!";
		return;
	}
	lines[line].makeHeading();
}

void Text::makeWordItallic(size_t line, size_t start, size_t end) {
	if (size <= line) {
		std::cerr << "No such line present!";
		return;
	}
	lines[line].makeItalic(start, end);
}

void Text::makeWordBold(size_t line, size_t start, size_t end) {
	if (size <= line) {
		std::cerr << "No such line present!";
		return;
	}
	lines[line].makeBold(start, end);
}

void Text::makeWordCombined(size_t line, size_t start, size_t end) {
	if (size <= line) {
		std::cerr << "No such line present!";
		return;
	}
	lines[line].makeCombined(start, end);
}

void Text::free() {
	delete[] filename;
	delete[] lines;
	filename = nullptr;
	lines = nullptr;
	size = 0;
	capasity = 0;
}

void Text::copy(const Text& rhs) {
	setFilename(rhs.filename);
	capasity = rhs.capasity;
	size = rhs.size;
	lines = new Line[capasity];
	for (int i = 0; i < size; i++) {
		lines[i] = rhs.lines[i];
	}
}

void Text::resize() {
	Line* temp;
	size_t newCapasity;
	if (size >= capasity) {
		newCapasity = capasity * 2;
	}
	else {
		newCapasity = capasity / 2;
	}
	temp = new Line[newCapasity];
	for (int i = 0; i < size; i++) {
		temp[i] = lines[i];
	}
	delete[] lines;
	lines = temp;
	capasity = newCapasity;
}

void Text::setFilename(const char* rhs) {
	this->filename = new char[strlen(rhs) + 1];
	strcpy(this->filename, rhs);
}

void Text::loadTextFile() {
	std::ifstream file(filename, std::ios::in);
	if (!file.good()) {
		std::cerr << "Input file stream failed!" << std::endl;
		return;
	}
	char buffer[maxLineSize];
	while (file.getline(buffer, maxLineSize)) {
		addLine(buffer);
	}
	file.close();
}

void Text::saveMarkDownFile() {
	char ext[3] = { "md" };
	char* mdFile = new char[strlen(filename)];//without +1 for a reason
	strncpy(mdFile, filename, strlen(filename) - 3);//Getting rid of extension
	mdFile[strlen(filename) - 3] = '\0';
	strcat(mdFile, ext);
	std::ofstream file(mdFile, std::ios::out | std::ios::trunc);
	if (!file.good()) {
		std::cerr << "Output file stream failed!" << std::endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		lines[i].writeLine(file);
	}
	file.close();
}
