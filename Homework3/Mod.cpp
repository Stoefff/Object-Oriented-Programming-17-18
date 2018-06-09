#include "Mod.h"
#include <iostream>

using std::cout;
using std::endl;

Mod::Mod(const char* name, const size_t age) 
	:User(name, age){
	cout << "User " << this->nickName << " is promoted to Mod!" << endl;
}

Mod::Mod(const Mod& rhs) 
	:User(rhs){
}

Mod& Mod::operator=(const Mod& rhs) {
	if (this != &rhs) {
		User::operator=(rhs);
	}
	return *this;
}

Mod::~Mod() {
}

void Mod::removePost(User* user, const size_t ID) {
	user->removeOwnPost(ID);
}

void Mod::blockUser(User* user) {
	user->beBlocked();
}

void Mod::unblockUser(User* user) {
	user->beUnblocked();
}