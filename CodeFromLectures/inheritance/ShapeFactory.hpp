/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2018
*/
#ifndef SHAPEFACTORY_HPP_INCLUDED
#define SHAPEFACTORY_HPP_INCLUDED

#include "shape.hpp"
#include <string>

// ���� ������� �� ��������� �� ������ �� ����� � �����
class ShapeFactory
{
public:
    // �� �� � ���������!
    static ShapeFactory& getFactory()
    {
        static ShapeFactory theFactory;
        return theFactory;
    }

    // ����� �� ����������� �� ���������� ���� �������
    void registerShape(const ShapeCreator* creator)
    {
        creators[cnt++] = creator;      // ������ �� ��������� � ���� �� ������
    }

    // ����� �������
    Shape* createShape(istream& stream)
    {
        // ����� �������
        std::string command;
        stream >> command;

        // � �������� �� ������� ���� �������, ����� � �������
        const ShapeCreator* crt = getCreator(command);
        if (crt)
        {
            // ��� �� - ������ ������� ���������� �����
            //  � �������� ��� �� �� ������
            return crt->createShape(stream);
        }
        else
        {
            // ����� ���������� �� ���� �� ���� � �������, �� �� � ��
            stream.ignore(4096, '\n');
            return NULL;
        }
    }

private:
    // ����� �� ������� �� ��������� �������
    const ShapeCreator* getCreator(const std::string& str) const
    {
        // ������ ������ ������ ������������ ���� �������� ���������
        for (int i = 0; i < cnt; ++i)
            // ��� �� - �������� ��� ������� ������
            if (creators[i]->getCommand() == str)
                return creators[i];

        // ��� ����� �� �� ������ ��������� - ������� ��������� ��������
        return NULL;
    }

private:
    // �������������� ����
    ShapeFactory():cnt(0){};
    ~ShapeFactory(){}

    ShapeFactory(const ShapeFactory&) = delete;
    ShapeFactory& operator=(const ShapeFactory&) = delete;

private:
    // � ��������� ����� - ������������ �������
    const ShapeCreator* creators[10];
    int cnt;
};

#endif // SHAPEFACTORY_HPP_INCLUDED
