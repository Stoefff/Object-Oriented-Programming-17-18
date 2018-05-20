#include "Meeting.h"
#include <iostream>
#include <cstring>

Meeting::Meeting(const char* desc, const char start[maxSizeDate], const char end[maxSizeDate],
    char* name): Appointment(desc, start, end)
    ,name(nullptr){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Meeting::Meeting(const Meeting& rhs)
    :Appointment(rhs){ //cast happends here
    copy(rhs);
}

Meeting& Meeting::operator=(const Meeting& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Meeting::~Meeting(){
    free();
}

void Meeting::free(){
    delete[] name;
    name = nullptr;
}

void Meeting::copy(const Meeting& rhs){
    this->name = new char[strlen(rhs.name) + 1];
    strcpy(this->name, rhs.name);
}

char* Meeting::getName() const {
    return this->name;
}
