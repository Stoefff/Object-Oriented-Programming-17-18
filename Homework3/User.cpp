#include "User.h"
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

User::User(const char* name, const size_t age) 
	:nickName(nullptr)
	,age(age)
	,postIDs(nullptr)
	,postsCount(0)
	,postsCapasity(2)
	,isBlocked(false){
	this->postIDs = new size_t[postsCapasity];
	this->nickName = new char[strlen(name) + 1];
	strcpy(this->nickName, name);
	cout << "User " << this->nickName << " created!" << endl;

}

User::User(const User& rhs) {
	copy(rhs);
}

User& User::operator=(const User& rhs) {
	if (this != &rhs) {
		free();
		copy(rhs);
	}
	return *this;
}

User::~User() {
	cout << "User " << this->nickName << " is now removed!" << endl;
	free();
}

void User::free() {
	delete[] nickName;
	nickName = nullptr;
	delete[] postIDs;
	postIDs = nullptr;
	age = 0;
	postsCount = 0;
	postsCapasity = 0;
	isBlocked = false;
}

void User::copy(const User& rhs) {
	this->nickName = new char[strlen(rhs.nickName) + 1];
	strcpy(this->nickName, rhs.nickName);
	this->age = rhs.age;
	this->postsCount = rhs.postsCount;
	this->postsCapasity = rhs.postsCapasity;
	this->postIDs = new size_t[this->postsCapasity];
	for (int i = 0; i < this->postsCount; i++) {
		this->postIDs[i] = rhs.postIDs[i];
	}
	this->isBlocked = rhs.isBlocked;
}

void User::resize() {
	size_t* temp = new size_t[postsCapasity * 2];
	for (int i = 0; i < postsCount; i++) {
		temp[i] = postIDs[i];
	}
	delete[] postIDs;
	postIDs = temp;
	temp = nullptr;
	postsCapasity *= 2;
	//cout << "Resize complete!" << endl;
}

void User::beBlocked() {
	this->isBlocked = true;
	cout << "User " << this->nickName << " was blocked!" << endl;
}

void User::beUnblocked() {
	this->isBlocked = false;
	cout << "User " << this->nickName << " was unblocked!" << endl;
}

bool User::isUserBlocked() const {
	return this->isBlocked;
}

size_t User::getAge() const {
	return this->age;
}

void User::addPost(const size_t ID) {
	for (int i = 0; i < postsCount; i++) {
		if (ID == postIDs[i]) {
			cerr << "Repetition of post not allowed for user " 
				<< this->nickName << "!" << endl;
			return;
		}
	}
	if (postsCount == postsCapasity) {
		resize();
	}
	postIDs[postsCount] = ID;
	postsCount++;
	//cout << "Post " << ID << " created" << endl;
}

int User::getPostPos(const size_t ID) const {
	if (postsCount == 0) {
		return -1;
	}
	size_t i = 0;
	if (postsCount > 0) {
		while (i < postsCount && postIDs[i] != ID) {
			i++;
		}
	}
	if (i == postsCount) {
		return -1;
	}
	return i;
}

void User::removeOwnPost(const size_t ID) {
	int postPos = getPostPos(ID);
	if (postPos == -1) {
		cerr << "No post with such ID found in the user " 
			<< this->nickName << "!" << endl;
		return;
	}
	postIDs[postPos] = postIDs[postsCount - 1];
	postsCount--;
	//cout << "Post " << ID << " removed!" << endl;

}

void User::rename(const char* name) {
	cout << "User " << this->nickName;
	delete[] this->nickName;
	this->nickName = new char[strlen(name) + 1];
	strcpy(this->nickName, name);
	cout << " renamed to " << this->nickName << "!" << endl;
}

char* User::getName() const {
	return this->nickName;
}

bool User::doHaveID(const size_t ID) const {
	int postPos = getPostPos(ID);
	if (postPos == -1) {
		return false;
	} else {
		return true;
	}
}