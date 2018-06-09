#include "UserCollection.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

UserCollection::UserCollection() 
	:admin(nullptr)
	,users(nullptr)
	,usersSize(0)
	,usersCapasity(2)
	,mods(nullptr)
	,modsSize(0)
	,modsCapasity(2){
// This is MINE implementation of FMIBook, so i will
// always be the admin
	admin = Admin::getInstance("Admin", 20);
	users = new User*[usersCapasity];
	mods = new Mod*[modsCapasity];
}

UserCollection& UserCollection::getInstance() {
	static UserCollection instance;
	return instance;
}

UserCollection::~UserCollection() {
	free();
}

void UserCollection::free() {
	for (int i = 0; i < usersSize; i++) {
		users[i] = admin->removeUser(users[i]);
	}
	delete[] users;
	users = nullptr;
	for (int i = 0; i < modsSize; i++) {
		mods[i] = admin->removeMod(mods[i]);
	}
	delete[] mods;
	mods = nullptr;
	delete admin;
}

void UserCollection::resizeUsers() {
	User** temp = new User*[usersCapasity * 2];
	for (int i = 0; i < usersSize; i++) {
		temp[i] = users[i];
	}
	delete[] users;
	users = temp;
	temp = nullptr;
	usersCapasity *= 2;
}

void UserCollection::resizeMods() {
	Mod** temp = new Mod*[modsCapasity * 2];
	for (int i = 0; i < modsSize; i++) {
		temp[i] = mods[i];
	}
	delete[] mods;
	mods = temp;
	temp = nullptr;
	modsCapasity *= 2;
}

int UserCollection::getUserPos(const char* name) const {
	if (usersSize == 0) {
		return -1;
	}
	size_t i = 0;
	if (usersSize > 0) {
		while (i < usersSize && _stricmp(name, users[i]->getName())) {
			i++;
		}
	}
	if (i == usersSize) {
		return -1;
	}
	return i;
}

int UserCollection::getModPos(const char* name) const {
	if (modsSize == 0) {
		return -1;
	}
	size_t i = 0;
	if (modsSize > 0) {
		while (i < modsSize && _stricmp(name, mods[i]->getName())) {
			i++;
		}
	}
	if (i == modsSize) {
		return -1;
	}
	return i;
}

bool UserCollection::isUserNameTaken(const char* name) const {
	if (getUserPos(name) != -1) {
		return true;
	}
	if (getModPos(name) != -1) {
		return true;
	}
	if (_stricmp(admin->getName(), name) == 0) {
		return true;
	}
	return false;
}

size_t UserCollection::getUsersSize() const {
	return this->usersSize;
}

void UserCollection::addUser(const char* admin, const char* name, size_t age) {
	if (_stricmp(admin, this->admin->getName()) != 0) {
		cerr << admin << " have to rights to add new users!" << endl;
		return;
	}
	if (getUserPos(name) != -1) {
		cerr << "User with the name " << name << " already exits!" << endl;
		return;
	}
	if (usersSize == usersCapasity) {
		resizeUsers();
	}
	users[usersSize] = this->admin->addUser(name, age);
	usersSize++;
}

void UserCollection::removeUser(const char* name) {
	int userPos = getUserPos(name);
	users[userPos] = this->admin->removeUser(users[userPos]);
	users[userPos] = users[usersSize - 1];
	users[usersSize - 1] = nullptr;
	usersSize--;
}

size_t UserCollection::getModsSize() const {
	return this->modsSize;
}

void UserCollection::addMod(const char* admin, const char* name, size_t age) {
	if (_stricmp(admin, this->admin->getName()) != 0) {
		cerr << admin << " have to rights to add new users!" << endl;
		return;
	}
	if (getModPos(name) != -1) {
		cerr << "User with the name " << name << " already exits!" << endl;
		return;
	}
	if (modsSize == modsCapasity) {
		resizeMods();
	}
	mods[modsSize] = this->admin->addMod(name, age);
	modsSize++;
}

void UserCollection::removeMod(const char* name) {
	int modPos = getModPos(name);
	mods[modPos] = this->admin->removeMod(mods[modPos]);
	mods[modPos] = mods[modsSize - 1];
	mods[modsSize - 1] = nullptr;
	modsSize--;
}

bool UserCollection::isUserBlocked(const char* name) const {
	int userPos = getUserPos(name);
	if (userPos != -1) {
		return users[userPos]->isUserBlocked();
	}
	userPos = getModPos(name);
	if (userPos != -1) {
		return mods[userPos]->isUserBlocked();
	}
	if (_stricmp(name, admin->getName()) == 0) {
		return admin->isUserBlocked();
	}
	else {
		cerr << "No user with name " << name << " found!" << endl;
		return true;
	}
}

int UserCollection::getAge(const char* name) const {
	int userPos = getUserPos(name);
	if (userPos != -1) {
		return users[userPos]->getAge();
	}
	userPos = getModPos(name);
	if (userPos != -1) {
		return mods[userPos]->getAge();
	}
	if (_stricmp(name, admin->getName()) == 0) {
		return admin->getAge();
	}
	else {
		cerr << "No user with name " << name << " found!" << endl;
		return -1;
	}
}

void UserCollection::addPost(const char* name, const size_t ID) {
	int userPos = getUserPos(name);
	if (userPos != -1) {
		if (!(users[userPos]->isUserBlocked())) {
			users[userPos]->addPost(ID);
		}
		else {
			cerr << "User " << name << " is blocked!" << endl;
		}
		return;
	}
	userPos = getModPos(name);
	if (userPos != -1) {
		if (!(mods[userPos]->isUserBlocked())) {
			mods[userPos]->addPost(ID);
		}
		else {
			cerr << "Mod " << name << " is blocked!" << endl;
		}
		return;
	}
	if (_stricmp(name, admin->getName()) == 0) {
		if (!(admin->isUserBlocked())) {
			admin->addPost(ID);
		}
		else {
			cerr << "Mod " << name << " is blocked!" << endl;
		}
		return;
	}
	else {
		cerr << "No user with name " << name << " found!" << endl;
		return;
	}
}

void UserCollection::rename(const char* name, const char* newName) {
	int userPos = getUserPos(name);
	if (userPos != -1) {
		users[userPos]->rename(newName);
		return;
	}
	userPos = getModPos(name);
	if (userPos != -1) {
		mods[userPos]->rename(newName);
		return;
	}
	if (_stricmp(name, admin->getName()) == 0) {
		admin->rename(newName);
		return;
	}
	else {
		cerr << "No user with name " << name << " found!" << endl;
		return;
	}
}

void UserCollection::removePost(const char* name, const size_t ID) {
	int userPos = getUserPos(name);
	if (userPos != -1) {
		users[userPos]->removeOwnPost(ID);
		return;
	}
	userPos = getModPos(name);
	if (userPos != -1) {
		if (mods[userPos]->doHaveID(ID)) {
			mods[userPos]->removeOwnPost(ID);
			return;
		}
		for (int i = 0; i < usersSize; i++) {
			if (users[i]->doHaveID(ID)) {
				mods[userPos]->removePost(users[i], ID);
				return;
			}
		}
		for (int i = 0; i < modsSize; i++) {
			if (mods[i]->doHaveID(ID)) {
				mods[userPos]->removePost(users[i], ID);
				return;
			}
		}
		if (admin->doHaveID(ID)) {
			mods[userPos]->removePost(admin, ID);
			return;
		}
	}
	if (_stricmp(name, admin->getName()) == 0) {
		if (admin->doHaveID(ID)) {
			admin->removeOwnPost(ID);
			return;
		}
		for (int i = 0; i < usersSize; i++) {
			if (users[i]->doHaveID(ID)) {
				admin->removePost(users[i], ID);
				return;
			}
		}
		for (int i = 0; i < modsSize; i++) {
			if (mods[i]->doHaveID(ID)) {
				admin->removePost(users[i], ID);
				return;
			}
		}
	}
	else {
		cerr << "No user with name " << name << " found!" << endl;
		return;
	}
}

void UserCollection::blockUser(const char* name, const char* blockedGuy) {
	int userPos = getModPos(name);
	if (userPos != -1) {
		int blockedPos = getUserPos(blockedGuy);
		if (blockedPos != -1) {
			mods[userPos]->blockUser(users[blockedPos]);
			return;
		}
		blockedPos = getModPos(blockedGuy);
		if (blockedPos != -1) {
			mods[userPos]->blockUser(mods[blockedPos]);
			return;
		}
		if (_stricmp(blockedGuy, admin->getName()) == 0) {
			mods[userPos]->blockUser(admin);
			return;
		}
	}
	if (_stricmp(name, admin->getName()) == 0) {
		int blockedPos = getUserPos(blockedGuy);
		if (blockedPos != -1) {
			admin->blockUser(users[blockedPos]);
			return;
		}
		blockedPos = getModPos(blockedGuy);
		if (blockedPos != -1) {
			admin->blockUser(mods[blockedPos]);
			return;
		}
		if (_stricmp(blockedGuy, admin->getName()) == 0) {
			admin->blockUser(admin);
			return;
		}
		else {
			cerr << "No user with name " << blockedGuy 
				<< " found to be blocked!" << endl;
			return;
		}
	}
	else {
		cerr << "No mod with name " << name << " found!" << endl;
		return;
	}
}

void UserCollection::unblockUser(const char* name, const char* unblockedGuy) {
	int userPos = getModPos(name);
	if (userPos != -1) {
		int unblockedPos = getUserPos(unblockedGuy);
		if (unblockedPos != -1) {
			mods[userPos]->unblockUser(users[unblockedPos]);
			return;
		}
		unblockedPos = getModPos(unblockedGuy);
		if (unblockedPos != -1) {
			mods[userPos]->unblockUser(mods[unblockedPos]);
			return;
		}
		if (_stricmp(unblockedGuy, admin->getName()) == 0) {
			mods[userPos]->unblockUser(admin);
			return;
		}
	}
	if (_stricmp(name, admin->getName()) == 0) {
		int unblockedPos = getUserPos(unblockedGuy);
		if (unblockedPos != -1) {
			admin->unblockUser(users[unblockedPos]);
			return;
		}
		unblockedPos = getModPos(unblockedGuy);
		if (unblockedPos != -1) {
			admin->unblockUser(mods[unblockedPos]);
			return;
		}
		if (_stricmp(unblockedGuy, admin->getName()) == 0) {
			admin->unblockUser(admin);
			return;
		}
		else {
			cerr << "No user with name " << unblockedGuy 
				<< " found to be unblocked!" << endl;
			return;
		}
	}
	else {
		cerr << "No mod with name " << name << " found!" << endl;
		return;
	}
}

void UserCollection::removePerson(const char* admin, const char* name) {
	if (_stricmp(admin, this->admin->getName()) != 0) {
		cerr << admin << " have to rights to add new users!" << endl;
		return;
	}
	int userPos = getUserPos(name);
	if (userPos != -1) {
		removeUser(name);
		return;
	}
	userPos = getModPos(name);
	if (userPos != -1) {
		removeMod(name);
		return;
	}
	else {
		cerr << "No user with name " << name 
			<< " found to be removed!" << endl;
	}
}