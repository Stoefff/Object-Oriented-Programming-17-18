#ifndef __ADMIN__HEADER__
#define __ADMIN__HEADER__

#include "Mod.h"

// I thougth about making Admin a singleton
// But then i wound not be able to move it in User Collection
class Admin : public Mod {
public:
	static Admin* getInstance(const char* name, const size_t age);
	Admin(const Admin& rhs) = delete;
	Admin& operator=(const Admin& rhs) = delete;
	~Admin();

	User* addUser(const char* name, const size_t age);
	User* removeUser(User* user);

	Mod* addMod(const char* name, const size_t age);
	Mod* removeMod(Mod* mod);

private:
	Admin(const char* name, const size_t age);
};

#endif
