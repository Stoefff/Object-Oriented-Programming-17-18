#ifndef __CIRCLE__HEADER__INCLUDED__
#define  __CIRCLE__HEADER__INCLUDED__

#include "Figure.h"
#include "Color.h"

class Circle: public Figure{
public:
	Circle(Point, Color, int);
	virtual ~Circle();

	virtual void print() const ;
	virtual void printPerimeter() const ;
	virtual void printArea() const ;

private:
	int radius;
};

#endif // ! __CIRCLE__HEADER__INCLUDED__
