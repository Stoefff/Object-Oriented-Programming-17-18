#include "Link.h"

using std::endl;

Link::Link(const char* content, const char* desc) 
	:Post(content){
	this->desc = new char[strlen(desc) + 1];
	strcpy(this->desc, desc);
}

Link::Link(const Link& rhs) 
	:Post(rhs){
	copy(rhs);
}

Link& Link::operator=(const Link& rhs) {
	if (this != &rhs) {
		Post::operator=(rhs);
		free();
		copy(rhs);
	}
	return *this;
}

Link::~Link() {
	free();
}

void Link::free() {
	delete[] this->desc;
	this->desc = nullptr;
}

void Link::copy(const Link& rhs) {
	this->desc = new char[strlen(rhs.desc) + 1];
	strcpy(this->desc, rhs.desc);
}

void Link::addContentToHTML(ofstream& file) const {
	file << "<p><a href=\""
		<< this->content
		<< "\">"
		<< desc
		<< "</a></p>" << endl;
}

Post* Link::clone() const {
	return new Link(*this);
}