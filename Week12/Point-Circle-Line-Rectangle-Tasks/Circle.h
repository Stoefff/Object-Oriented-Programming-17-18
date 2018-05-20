#ifndef __CIRCLE__HEADER__INCLUDED__
#define  __CIRCLE__HEADER__INCLUDED__

#include "Figure.h"
#include "Color.h"

class Circle: public Figure{
public:
	Circle(Point center, int radius, Color circleColor);
	virtual ~Circle();

	void translate(int horizontal, int vertical);
	const void print() const;

private:
	int radius;
};

#endif // ! __CIRCLE__HEADER__INCLUDED__
