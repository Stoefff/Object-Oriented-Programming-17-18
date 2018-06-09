#include "Picture.h"
#include <cstring>
#include <fstream>

using std::ofstream;
using std::endl;

//Default G4 should work here because we have no added dynamic data
//and compilers optimize the dafault G4 methods of such derived classes
//But let's not risk it :)

Picture::Picture(const char* content)
	:Post(content) {
}

Picture::Picture(const Picture& rhs) 
	:Post(rhs){
}

Picture& Picture::operator=(const Picture& rhs) {
	if (this != &rhs) {
		Post::operator=(rhs);
	}
	return *this;
}

Picture::~Picture(){
}

void Picture::addContentToHTML(ofstream& file) const {
	file << "<img src = \""
		<< this->content
		<< "\">" << endl;
}

Post* Picture::clone() const {
	return new Picture(*this);
}