/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2018
*/

#ifndef __POINT_HEADER_INCLUDED_
#define __POINT_HEADER_INCLUDED_

#include <iostream>

// ������� ���� �����. �������� �� �� �������� �� ������ ����������, ����� � ������ � 2D
class Point
{
public:
    // ����������� � ��������� �� ������������
    Point(int x = 0, int y = 0);

    // ������ �� ������ �� ������������
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    // ��� ������ �� ������� �� ������� �� �����
    void moveWith(const Point & vec);   // ����������
    void moveTo(const Point & point);   // �����������

    void print(std::ostream& os) const;
    void read (std::istream& is);
private:
    // �� �������� �� ������ ����������� ����������
    int x, y;
};

#endif // __POINT_HEADER_INCLUDED_
