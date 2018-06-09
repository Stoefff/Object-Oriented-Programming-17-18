/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2018
*/
#ifndef SHAPEFACTORY_HPP_INCLUDED
#define SHAPEFACTORY_HPP_INCLUDED

#include "shape.hpp"
#include <string>

// Клас фабрика за създаване на фигури по данни в поток
class ShapeFactory
{
public:
    // Тя ще е сингълтон!
    static ShapeFactory& getFactory()
    {
        static ShapeFactory theFactory;
        return theFactory;
    }

    // Метод за регистрация на абстрактен клас фабрика
    void registerShape(const ShapeCreator* creator)
    {
        creators[cnt++] = creator;      // просто го забучваме в края на масива
    }

    // Метод фабрика
    Shape* createShape(istream& stream)
    {
        // Четем команда
        std::string command;
        stream >> command;

        // и опитваме да намерим клас фабрика, който я разбира
        const ShapeCreator* crt = getCreator(command);
        if (crt)
        {
            // Ако да - фикаме неговия абстрактен метод
            //  и оставяме той да се оправя
            return crt->createShape(stream);
        }
        else
        {
            // Иначе прескачаме до края на реда и казваме, че не е ОК
            stream.ignore(4096, '\n');
            return NULL;
        }
    }

private:
    // Метод за търсене на подходяща фабрика
    const ShapeCreator* getCreator(const std::string& str) const
    {
        // Питаме подред всички регистрирани дали познават командата
        for (int i = 0; i < cnt; ++i)
            // Ако да - намерили сме каквото искаме
            if (creators[i]->getCommand() == str)
                return creators[i];

        // Ако никой не си познае командата - връщаме невалидна стойност
        return NULL;
    }

private:
    // Сингълтонските неща
    ShapeFactory():cnt(0){};
    ~ShapeFactory(){}

    ShapeFactory(const ShapeFactory&) = delete;
    ShapeFactory& operator=(const ShapeFactory&) = delete;

private:
    // И собствени данни - регистрирани фабрики
    const ShapeCreator* creators[10];
    int cnt;
};

#endif // SHAPEFACTORY_HPP_INCLUDED
