/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2018
*/

#ifndef __FILLED_CIRCLE_HEADER_INCLUDED_
#define __FILLED_CIRCLE_HEADER_INCLUDED_

#include "circle.hpp"
#include <string>
using std::string;

// По-широк вид окръжност - Запълнена с фон окръжност.
// Тя Е СЪЩО окръжност - наследява Circle
class FilledCircle : public Circle
{
public:
    FilledCircle(const Point& center, int r, const char* color = "white");
    FilledCircle(const FilledCircle& rhs);
    ~FilledCircle();
    FilledCircle& operator=(const FilledCircle& rhs);

    // Предефинира единствено метода за извеждане на информация
    void print() const;

    Shape* clone() const;
private:
    // Има специфични данни за цвят
    char* color;
};


class FCCreator : public ShapeCreator
{
public :
    FCCreator() : ShapeCreator("filled"){}  // Задаваме команда filled
    Shape* createShape(istream&) const;
};

#endif // __FILLED_CIRCLE_HEADER_INCLUDED_
