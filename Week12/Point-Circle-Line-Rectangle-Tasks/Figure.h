#ifndef __FIGURE__HEADER
#define __FIGURE__HEADER

#include "Point.h"
#include "Color.h"

class Figure{
public:
    Figure(Point, Color);
    virtual ~Figure();
    //Defaut copy costructor and operator = would work?

    virtual void print() const = 0;
    virtual void printPerimeter() const = 0;
    virtual void printArea() const = 0;

    void translate(int, int);

protected:
    Point center;
    Color color;
};

#endif
