#ifndef __POST__HEADER__
#define __POST__HEADER__

#include <fstream>
	
using std::ofstream;

class Post {
public:
	Post(const char* content);
	Post(const Post& rhs);
	Post& operator=(const Post& rhs);
	virtual ~Post();

	size_t getID() const;
	void viewPost(const char* name) const;
	virtual Post* clone() const = 0;

protected:
	virtual void addContentToHTML(ofstream& file) const = 0;

private:
	char* createFileName(const char* name) const;

	void free();
	void copy(const Post& rhs);

protected:
	char* content;
	size_t id;
};

#endif
