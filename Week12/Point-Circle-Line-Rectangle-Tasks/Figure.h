#ifndef __FIGURE__HEADER
#define __FIGURE__HEADER
#include "Point.h"


class Figure{
public:
    Figure(Point, const char*);
    virtual ~Figure();

    virtual void print() = 0;
    virtual void getPerimeter() = 0;
    virtual void getArea() = 0;

private:
    Point center;
    char* color;
};

#endif
