#include "Person.h"
#include <iostream>
#include <cstring>

Person::Person(const char* name, const uint date)
    :name(nullptr)
    ,date(date){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
}

Person::Person(const Person& rhs){
    copy(rhs);
}

Person& Person::operator=(const Person& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Person::~Person(){
    free();
}

void Person::copy(const Person& rhs){
    this->name = new char[strlen(rhs.name) + 1];
    strcpy(this->name, rhs.name);
    this->date = rhs.date;
}

void Person::free(){
    delete this->name;
    this->name = nullptr;
    this->date = 0;
}

void Person::print() const {
    std::cout << this->name << std::endl
        << this->date << std::endl;
}
