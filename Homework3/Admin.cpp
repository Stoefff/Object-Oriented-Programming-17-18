#include "Admin.h"
#include "iostream"

using std::cout;
using std::endl;

Admin::Admin(const char* name, const size_t age) 
	:Mod(name, age){
	cout << "User " << this->nickName << " is now promoted to THE ADMIN!!!" << endl;
}

Admin::~Admin() {
}

Admin* Admin::getInstance(const char* name, const size_t age) {
	//this line could be a big mistake
	//Potential memory leak, when calling getInstance, more than once
	//Ask Vasi/Paco/Niki about this
	static Admin* instance = new Admin(name, age);
	return instance;
}

User* Admin::addUser(const char* name, const size_t age) {
	return new User(name, age);
}

User* Admin::removeUser(User* user) {
	delete user;
	user = nullptr;
	return user;
}

Mod* Admin::addMod(const char* name, const size_t age) {
	return new Mod(name, age);
}

Mod* Admin::removeMod(Mod* mod) {
	delete mod;
	mod = nullptr;
	return mod;
}