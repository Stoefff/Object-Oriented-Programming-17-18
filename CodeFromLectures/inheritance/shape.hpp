/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2018
*/

#ifndef __SHAPE_HEADER_INCLUDED_
#define __SHAPE_HEADER_INCLUDED_

#include "point.hpp"

// Базов клас описващ произволна фигура.
// Използва (наслоява) точка
class Shape
{
public:
    Shape();
    virtual ~Shape();   // ЗАДЪЛЖИТЕЛНО виртуален деструктор!!!!

    // Общи методи за всички форми
    virtual void moveWith(const Point& vec);    // Транслация
    virtual double getArea() const = 0;         // Изчислява лицето -> чисто виртуален
    virtual void print() const;                 // Извежда информация за фигурата

    virtual Shape* clone() const = 0;           // Създава ПОЛИМОРФНО копие на обекта. Чисто виртуален

protected:
    // Понеже ограждащия правоъгълник е специфична данна
    // се осигуряват защитени методи за достъп.
    Point getTopLeft() const;
    void setTopLeft(const Point&);

    Point getBtmRight() const;
    void setBtmRight(const Point&);

private:
    // Помощен метод за поправка на ограждащия правоъгълник.
    // Използва се след промяна на някой от координатите му.
    void swapIfNeeded();

private:
    // Координати на ограждащия правоъгълник
    // Заради специфичния контрол на достъпа за частни
    Point TL, BR;
};

// Клас нужен за да реализираме абстрактна фабрика
class ShapeCreator
{
public:
    ShapeCreator(const char* cmd);      // създава се по име команда
    virtual ~ShapeCreator() {}          // ЗАДЪЛЖИТЕЛНО виртуален деструктор
    const char* getCommand() const {return cmd;}

    // Чисто виртуален метод, носещ знанието за създаване на специфична фигура
    virtual Shape* createShape(istream&) const = 0;

protected:
    // Команда по която ще се разпознава
    const char* cmd;
};

#endif // __SHAPE_HEADER_INCLUDED_
