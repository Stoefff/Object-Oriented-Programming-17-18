/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2018
*/

#ifndef __CIRCLE_HEADER_INCLUDED_
#define __CIRCLE_HEADER_INCLUDED_

#include "point.hpp"
#include "shape.hpp"

// Окръжност. Тя Е СЪЩО форма - наследява Shape
// Използва (наслоява върху) Point
class Circle : public Shape
{
public:
    Circle(const Point& center, int r);

    // Специфични за окръжността методи
    Point getCenter() const;
    void resize(unsigned int radius);   // Променя радиуса на окръжността

    // Собствени имплементации на методите наследени от Shape
    void moveTo(const Point& center);
    double getArea() const;
    void print() const;

    Shape* clone() const;
private:
    Point center;
    int radius;
};

class CircleCreator : public ShapeCreator
{
public :
    CircleCreator() : ShapeCreator("circle"){}  // Задаваме команда circle
    Shape* createShape(istream&) const;
};

#endif // __CIRCLE_HEADER_INCLUDED_
