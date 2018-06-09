#ifndef __MOD__HEADER__
#define __MOD__HEADER__

#include "User.h"

class Mod : public User {
public:
	void removePost(User* user, const size_t ID);
	void blockUser(User* user);
	void unblockUser(User* user);

	friend class Admin;
protected:
	Mod(const char* name, const size_t age);
	Mod(const Mod& rhs);
	Mod& operator=(const Mod& rhs);
	~Mod();

};

#endif
