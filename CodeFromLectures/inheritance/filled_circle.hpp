/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2018
*/

#ifndef __FILLED_CIRCLE_HEADER_INCLUDED_
#define __FILLED_CIRCLE_HEADER_INCLUDED_

#include "circle.hpp"
#include <string>
using std::string;

// ��-����� ��� ��������� - ��������� � ��� ���������.
// �� � ���� ��������� - ��������� Circle
class FilledCircle : public Circle
{
public:
    FilledCircle(const Point& center, int r, const char* color = "white");
    FilledCircle(const FilledCircle& rhs);
    ~FilledCircle();
    FilledCircle& operator=(const FilledCircle& rhs);

    // ����������� ���������� ������ �� ��������� �� ����������
    void print() const;

    Shape* clone() const;
private:
    // ��� ���������� ����� �� ����
    char* color;
};


class FCCreator : public ShapeCreator
{
public :
    FCCreator() : ShapeCreator("filled"){}  // �������� ������� filled
    Shape* createShape(istream&) const;
};

#endif // __FILLED_CIRCLE_HEADER_INCLUDED_
