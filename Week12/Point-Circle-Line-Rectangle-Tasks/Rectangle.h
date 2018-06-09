#ifndef __RECTANGLE__HEADER__INCLUDED__
#define __RECTANGLE__HEADER__INCLUDED__

#include "Figure.h"

class Rectangle: public Figure{
public:
	Rectangle(Point, Color, int, int);
	virtual ~Rectangle();

	virtual void print() const;
	virtual void printPerimeter() const;
	virtual void printArea() const;

private:
	int width;
	int height;
};

#endif // !__RECTANGLE__HEADER__INCLUDED__
