#include "Text.h"

using std::endl;

Text::Text(const char* content)
	:Post(content){
}

Text::Text(const Text& rhs) 
	:Post(rhs){
}

Text& Text::operator=(const Text& rhs) {
	if (this != &rhs) {
		Post::operator=(rhs);
	}
	return *this;
}

Text::~Text() {
}

void Text::addContentToHTML(ofstream& file) const {
	file << "<p>" << content << "</p>" << endl;
}

Post* Text::clone() const {
	return new Text(*this);
}