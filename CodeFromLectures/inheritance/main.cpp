/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2018
*/

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "filled_circle.hpp"
#include "ShapeFactory.hpp"

#include <iostream>
#include <fstream>
using namespace std;

void print(const Shape& s)
{
    s.print();
    cout << "Area: " << s.getArea();
    cout << endl;
}

void printCircle(const Circle& c)
{
    c.print();
    cout << "Area: " << c.getArea();
    cout << endl;
}

void inheritanceTest()
{
    Point zero;
    Point point(3, 5);

// Това вече не работи!!!
/*
    cout << "Shape test: " << endl;
    Shape unknown;
    unknown.print();
    unknown.moveWith(point);
    unknown.print();
*/

    cout << "\n\nCircle test: " << endl;
    Circle c(zero, 3);
    print(c);
    printCircle(c);

    cout << "\n\nFilled Circle test: " << endl;
    FilledCircle fc(point, 5, "Black");
    print(Rectangle(zero, point));
    printCircle(fc);
    fc.print();
}

void polyDemo()
{
    // Четем данни за фигури от файл
    ifstream file("test.txt");
    if(!file) return;   // проверка за успешно отваряне - не я забравяме :)

    // четем броя на командите
    int s;
    file >> s;

    // и създаваме ПОЛИМОРФЕН контейнер с толкова на брой елемента
    Shape** picture = new Shape*[s];

    // Посредством вълшебната фабрика ги създаваме една по една
    for (int i = 0; i < s; ++i)
        picture[i] = ShapeFactory::getFactory().createShape(file);

    // След това обхождаме масива и правим нещо с него
    for (int i = 0; i < s; ++i)
    {
        if (picture[i])
        {
            picture[i]->print();     // ПОЛИМОРФНО поведение:)
            cout << endl << endl;
        }
        else
        {
            cout << "Bad or unknown shape!" << endl;
        }
    }

    // Накрая разчистваме след себе си
    for (int i = 0; i < s; ++i)
        delete picture[i];
    delete[] picture;
}


int main()
{
//    inheritanceTest();

    polyDemo();

    return 0;
}
