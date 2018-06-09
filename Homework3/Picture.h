#ifndef __PICTURE__HEADER__
#define __PICTURE__HEADER__

#include "Post.h"

class Picture : public Post {
public:
	Picture(const char* content);
	Picture(const Picture& rhs);
	Picture& operator=(const Picture& rhs);
	virtual ~Picture();

	virtual void addContentToHTML(ofstream& file) const override;
	virtual Post* clone() const override;

};

#endif