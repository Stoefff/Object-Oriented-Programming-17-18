/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2018
*/

#include "point.hpp"

#include <iostream>
using std::ostream;
using std::istream;

Point::Point(int x, int y)
{
    setX(x);
    setY(y);
}

int  Point::getX() const
{
    return x;
}

int  Point::getY() const
{
    return y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

void Point::moveWith(const Point & vec)
{
    x += vec.x;
    y += vec.y;
}

void Point::moveTo(const Point & vec)
{
    x = vec.x;
    y = vec.y;
}

void Point::print(ostream& os) const
{
    os << '(' << getX() << ", " << getY() << ')';
}

void Point::read(istream& is)
{
    char c;
    int coord;
    is >> c >> coord;
    setX(coord);
    is >> c >> coord;
    setY(coord);
    is >> c;
}
