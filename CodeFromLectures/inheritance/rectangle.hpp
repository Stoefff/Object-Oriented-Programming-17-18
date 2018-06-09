/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2018
*/

#ifndef __RECTANGLE_HEADER_INCLUDED_
#define __RECTANGLE_HEADER_INCLUDED_

#include "point.hpp"
#include "shape.hpp"

// ���� ������������.
// ��� � ���� � ����� ���� �� ��������� Shape
class Rectangle : public Shape
{
public:
    // �������� ������������
    Rectangle(const Point& TopLeft, int width, int height);
    Rectangle(const Point& TopLeft, const Point& BtmRight);

    // ��������� ������������� �� �������� �� Shape
    void moveTo(const Point& TopLeft);
    double getArea()const;
    void print() const;

    Shape* clone() const;

    // ������ �� ������ �� ����������� �� ����� (������ � ��������)
    void setWidth(unsigned int width);
    int getWidth() const;
    void setHeight(unsigned int height);
    int getHeight() const;

    // ������ �� ������ �� ���������.
    // ���������� ������������ �� ������������� �� ������� ����.
    // ���� ������ �� "�������� �� �������" �������� ������.
    // ����� ����������� ��� ��� �� �� ����������, �������, �� � �� ��������.
    using Shape::getTopLeft;
    using Shape::getBtmRight;

    // ���� ��� ������ �� ������ ���, �� � � ��-�������� ���������.
    //Point getTopLeft()const { return Shape::getTopLeft(); }
    //Point getBtmRight()const { return Shape::getBtmRight(); }
};


class RectangleCreator : public ShapeCreator
{
public :
    RectangleCreator() : ShapeCreator("rectangle"){}
    Shape* createShape(istream&) const;
};


#endif // __RECTANGLE_HEADER_INCLUDED_
