/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2018
*/

#ifndef __POINT_HEADER_INCLUDED_
#define __POINT_HEADER_INCLUDED_

#include <iostream>

// Помощен клас Точка. Използва се за задаване на двойка координати, както и вектор в 2D
class Point
{
public:
    // Конструктор с архументи по подразбиране
    Point(int x = 0, int y = 0);

    // методи за достъп до координатите
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    // Два метода за промяна на позиция на точка
    void moveWith(const Point & vec);   // транслация
    void moveTo(const Point & point);   // присвояване

    void print(std::ostream& os) const;
    void read (std::istream& is);
private:
    // За простота са израни целочислени координати
    int x, y;
};

#endif // __POINT_HEADER_INCLUDED_
