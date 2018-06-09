#include "PostCollection.h"
#include <cstring>
#include <iostream>

using std::cerr;
using std::endl;

PostCollection::PostCollection()
	:coll(nullptr)
	,size(0)
	,capasity(2){
	this->coll = new Post*[capasity];
}

PostCollection::~PostCollection() {
	free();
}

void PostCollection::free() {
	for (int i = 0; i < size; i++) {
		delete coll[i];
	}
	delete[] coll;
	coll = nullptr;
	size = 0;
}

PostCollection& PostCollection::getInstance() {
	static PostCollection instance;
	return instance;
}

//REMEMBER FOR LATER: the memory on the passed pointer
//should be `delete` after using this function
void PostCollection::addPost(const Post* post) {
	//maybe add exceptions also here
	if (post == nullptr) {
		cerr << "Enter valid post to enter" << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		if (post->getID() == coll[i]->getID()) {
			cerr << "Repetition of post not allowed in the collection! " << endl;
			return;
		}
	}
	if (size == capasity) {
		resize();
	}
	coll[size] = post->clone();
	size++;
}
// Write exception here later
int PostCollection::getPostPos(const size_t ID) const{
	if (size == 0) {
		return -1;
	}
	size_t i = 0;
	if (size > 0) {
		while (i < size && coll[i]->getID() != ID) {
			i++;
		}
	}
	if (i == size) {
		return -1;
	}
	return i;

}

void PostCollection::removePost(const size_t ID) {
	int postPos = getPostPos(ID);
	if (postPos == -1) {
		cerr << "No post with such ID found!" << endl;
		return;
	}
	delete coll[postPos];
	coll[postPos] = coll[size - 1];
	coll[size - 1] = nullptr;
	size--;
}

void PostCollection::resize() {
	Post** temp = new Post*[capasity * 2];
	for (int i = 0; i < size; i++) {
		temp[i] = coll[i];
	}
	delete[] coll;
	coll = temp;
	temp = nullptr;
	capasity *= 2;
}

void PostCollection::viewPost(size_t ID,const char* name) {
	for (int i = 0; i < size; i++) {
		if (ID == coll[i]->getID()) {
			coll[i]->viewPost(name);
			return;
		}
	}
	//Maybe replace this with exception later
	cerr << "No post with such ID found!" << endl;
}

size_t PostCollection::getSize() const {
	return this->size;
}