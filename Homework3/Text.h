#ifndef __TEXT__HEADER__
#define __TEXT__HEADER__

#include "Post.h"

class Text : public Post {
public:
	Text(const char* content);
	Text(const Text& rhs);
	Text& operator=(const Text& rhs);
	virtual ~Text();

	virtual void addContentToHTML(ofstream& file) const override;
	virtual Post* clone() const override;
};

#endif
