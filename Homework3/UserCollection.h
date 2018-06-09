#ifndef __USER__COLLECTION__HEADER__
#define __USER__COLLECTION__HEADER__

#include "User.h"
#include "Mod.h"
#include "Admin.h"

//Singleton
class UserCollection {
public:
	static UserCollection& getInstance();
	UserCollection(const UserCollection& rhs) = delete;
	UserCollection& operator=(const UserCollection& rhs) = delete;
	~UserCollection();

	size_t getUsersSize() const;
	void addUser(const char* admin, const char* name, size_t age);

	size_t getModsSize() const;
	void addMod(const char* admin, const char* name, size_t age);

	void removePerson(const char* admin, const char* name);
	void removePost(const char* name, const size_t ID);

	bool isUserBlocked(const char* name) const;
	int getAge(const char* name) const;
	void addPost(const char* name, const size_t ID);
	void rename(const char* name, const char* newName);

	void blockUser(const char* name, const char* blockedGuy);
	void unblockUser(const char* name, const char* unblockedGuy);

	bool isUserNameTaken(const char* name) const;

private:
	UserCollection();

	void free();
	void resizeUsers();
	void resizeMods();

	void removeUser(const char* name);
	void removeMod(const char* name);

	int getUserPos(const char* name) const;
	int getModPos(const char* name) const;

private:
	Admin* admin;
	User** users;
	size_t usersSize;
	size_t usersCapasity;
	Mod** mods;
	size_t modsSize;
	size_t modsCapasity;
};

#endif
