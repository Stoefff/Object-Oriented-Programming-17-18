/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2018
*/

#ifndef __FILLED_CIRCLE_HEADER_INCLUDED_
#define __FILLED_CIRCLE_HEADER_INCLUDED_

#include "circle.hpp"

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

private:
    void setColor(const char* color);
    char* color;
};

#endif // __FILLED_CIRCLE_HEADER_INCLUDED_
