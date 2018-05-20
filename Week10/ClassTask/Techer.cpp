#include "Teacher.h"
#include <iostream>
#include <cstring>

Teacher::Teacher(const char* name, const uint date,
                 const char* uniName, const char* subjectName)
                 :Person(name, date)
                 ,uniName(nullptr)
                 ,subjectName(nullptr){
                this->uniName = new char[strlen(uniName) + 1];
                strcpy(this->uniName, uniName);
                this->subjectName = new char[strlen(subjectName) + 1];
                strcpy(this->subjectName, subjectName);
}

Teacher::Teacher(const Teacher& rhs)
    :Person(rhs){
    copy(rhs);
}

Teacher& Teacher::operator=(const Teacher& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Teacher::~Teacher(){
    free();
}

void Teacher::free(){
    delete[] uniName;
    delete[] subjectName;
}

void Teacher::copy(const Teacher& rhs){
    this->uniName = new char[strlen(rhs.uniName) + 1];
    strcpy(this->uniName, rhs.uniName);
    this->subjectName = new char[strlen(rhs.subjectName) + 1];
    strcpy(this->subjectName, rhs.subjectName);
}

void Teacher::changeUni(const char* name){
    this->uniName = new char[strlen(name) + 1];
    strcpy(this->uniName, name);
}

void Teacher::changeSubject(const char* subject){
    this->subjectName = new char[strlen(subject) + 1];
    strcpy(this->subjectName, subject);
}

void Teacher::print() const {
    Person::print();
    std::cout << uniName << std::endl
                << subjectName << std::endl;
}
