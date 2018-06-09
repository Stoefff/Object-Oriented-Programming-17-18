#ifndef __POST__COLLECTION__HEADER__
#define __POST__COLLECTION__HEADER__

#include "Post.h"
#include "Picture.h"
#include "Text.h"
#include "Link.h"

//Singleton patter because PostCollectiong should have only
// one object in the whole system
class PostCollection {
public:
	static PostCollection& getInstance();
	PostCollection(const PostCollection& rhs) = delete;
	PostCollection& operator=(const PostCollection& rhs) = delete;
	~PostCollection();

	size_t getSize() const;

	void addPost(const Post* post);
// `addPost` could be rewritten as:
// void addPost(const char* content, const char* desc);
// but this would make `post->clone()` redundant
	void removePost(const size_t ID);
	void viewPost(const size_t ID, const char* name);

private:
	PostCollection();
	//~PostCollection();
	// No sure why here the destrcutor is private
	// But Armqnov has written so

	void free();
	void resize();
	int getPostPos(const size_t ID) const;

private:
	Post** coll;
	size_t size;
	size_t capasity;
};

#endif
