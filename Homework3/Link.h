#ifndef __LINK__HEADER__
#define __LINK__HEADER__

#include "Post.h"

class Link : public Post {
public:
	Link(const char* content, const char* desc);
	Link(const Link& rhs);
	Link& operator=(const Link& rhs);
	virtual ~Link();

	virtual void addContentToHTML(ofstream& file) const override;
	virtual Post* clone() const override;

private:
	void free();
	void copy(const Link& rhs);

private:
	char* desc;
};

#endif
