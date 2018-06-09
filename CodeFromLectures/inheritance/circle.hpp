/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2018
*/

#ifndef __CIRCLE_HEADER_INCLUDED_
#define __CIRCLE_HEADER_INCLUDED_

#include "point.hpp"
#include "shape.hpp"

// ���������. �� � ���� ����� - ��������� Shape
// �������� (�������� �����) Point
class Circle : public Shape
{
public:
    Circle(const Point& center, int r);

    // ���������� �� ����������� ������
    Point getCenter() const;
    void resize(unsigned int radius);   // ������� ������� �� �����������

    // ��������� ������������� �� �������� ��������� �� Shape
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
    CircleCreator() : ShapeCreator("circle"){}  // �������� ������� circle
    Shape* createShape(istream&) const;
};

#endif // __CIRCLE_HEADER_INCLUDED_
