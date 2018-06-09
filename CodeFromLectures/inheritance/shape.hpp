/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2018
*/

#ifndef __SHAPE_HEADER_INCLUDED_
#define __SHAPE_HEADER_INCLUDED_

#include "point.hpp"

// ����� ���� ������� ���������� ������.
// �������� (��������) �����
class Shape
{
public:
    Shape();
    virtual ~Shape();   // ������������ ��������� ����������!!!!

    // ���� ������ �� ������ �����
    virtual void moveWith(const Point& vec);    // ����������
    virtual double getArea() const = 0;         // ��������� ������ -> ����� ���������
    virtual void print() const;                 // ������� ���������� �� ��������

    virtual Shape* clone() const = 0;           // ������� ���������� ����� �� ������. ����� ���������

protected:
    // ������ ���������� ������������ � ���������� �����
    // �� ���������� �������� ������ �� ������.
    Point getTopLeft() const;
    void setTopLeft(const Point&);

    Point getBtmRight() const;
    void setBtmRight(const Point&);

private:
    // ������� ����� �� �������� �� ���������� ������������.
    // �������� �� ���� ������� �� ����� �� ������������ ��.
    void swapIfNeeded();

private:
    // ���������� �� ���������� ������������
    // ������ ����������� ������� �� ������� �� ������
    Point TL, BR;
};

// ���� ����� �� �� ����������� ���������� �������
class ShapeCreator
{
public:
    ShapeCreator(const char* cmd);      // ������� �� �� ��� �������
    virtual ~ShapeCreator() {}          // ������������ ��������� ����������
    const char* getCommand() const {return cmd;}

    // ����� ��������� �����, ����� �������� �� ��������� �� ���������� ������
    virtual Shape* createShape(istream&) const = 0;

protected:
    // ������� �� ����� �� �� ����������
    const char* cmd;
};

#endif // __SHAPE_HEADER_INCLUDED_
