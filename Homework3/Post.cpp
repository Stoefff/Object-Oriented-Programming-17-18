#include "Post.h"
#include "HelperFunctions.h"
#include <cstring>
#include <iostream>

using std::ofstream;
using std::ios;
using std::endl;
using std::cerr;
using std::cout;

static size_t ID = 0;
static const size_t addedSymbolsforFileName = 13;

Post::Post(const char* content)
	:content(nullptr)
	, id(ID++) {
	this->content = new char[strlen(content) + 1]; // Do this with exceptions
	strcpy(this->content, content);
	cout << "Post " << this->id << " created!" << endl;
}

Post::Post(const Post& rhs) {
	copy(rhs);
}

Post& Post::operator=(const Post& rhs) {
	if (this != &rhs) {
		free();
		copy(rhs);
	}
	return *this;
}

Post::~Post() {
	free();
}

void Post::free() {
	delete[] content;
	content = nullptr;
}

void Post::copy(const Post& rhs) {
	this->id = rhs.id;
	this->content = new char[strlen(rhs.content) + 1];
	strcpy(this->content, rhs.content);
}

size_t Post::getID() const {
	return this->id;
}

// This method was not initially `const` and debugged for days :(
char* Post::createFileName(const char* name) const {
	char* IDnumber = size_t_to_char(this->id);
	char* fileName = new char[strlen(name)
		+ strlen(IDnumber)
		+ addedSymbolsforFileName + 1];
	fileName[0] = '\0';
	strcat(fileName, name);
	strcat(fileName, "_viewed_");
	strcat(fileName, IDnumber);
	strcat(fileName, ".html");

	delete[] IDnumber;
	return fileName;
}

void Post::viewPost(const char* name) const {
	char* fileName = createFileName(name);
	ofstream file(fileName, ios::out | ios::trunc);
	// Replace this with exception
	if (!file.good()) {
		cerr << "Output file stream failed! " << endl;
	}
	file << "<!DOCTYPE html>" << endl
		<< "<html>" << endl
		<< "<body>" << endl;
	//Here I imply that the function is dynamically linked
	this->addContentToHTML(file);
	file << "</body>" << endl
		<< "</html>" << endl;
	file.close();
	delete[] fileName;
	cout << "HTML view for post " << this->id << " created!" << endl;
}
