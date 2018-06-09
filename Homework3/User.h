#ifndef __USER__HEADER__
#define __USER__HEADER__

class User {
public:
	bool isUserBlocked() const;
	size_t getAge() const;
	char* getName() const;
	bool doHaveID(const size_t ID) const;
	
	void addPost(const size_t ID);
	void removeOwnPost(const size_t ID);
	void rename(const char* name);

// If these 2 classes didn't have access to the User
// The G4 of User should be public , and it better not be
// Because only class Admin should have full access
	friend class Mod;
	friend class Admin;

protected:
	User(const char* name, const size_t age);
	User(const User& rhs);
	User& operator=(const User& rhs);
	~User();

private:
	void free();
	void copy(const User& rhs);
	void resize();
	int getPostPos(const size_t ID) const;

	void beBlocked();
	void beUnblocked();

private:
	char* nickName;
	size_t age;
	size_t* postIDs;
	size_t postsCount;
	size_t postsCapasity;
	bool isBlocked;
};

#endif
