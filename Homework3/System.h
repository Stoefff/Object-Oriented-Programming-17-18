#ifndef __SYSTEM__HEADER__
#define __SYSTEM__HEADER__

#include "PostCollection.h"
#include "UserCollection.h"

//Singleton
class System {
public:
	static System& getInstance();
	System(const System& rhs) = delete;
	System& operator=(const System& rhs) = delete;
	~System();

	void run();

private:
	System();

private:
	PostCollection* pC;
	UserCollection* uC;
};

#endif
