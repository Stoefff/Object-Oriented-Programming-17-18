#include "Appointment.h"
#include <cstring>

Appointment::Appointment(const char* desc, const char start[maxSizeDate],
    const char end[maxSizeDate] ){
    this->desc = new char[strlen(desc) + 1];
    strcpy(this->desc, desc);
    strcpy(this->start, start);
    strcpy(this->end, end);
}

Appointment::Appointment(const Appointment& rhs){
    copy(rhs);
}

Appointment& Appointment::operator=(const Appointment& rhs){
    if (this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Appointment::~Appointment(){
    free();
}

void Appointment::copy(const Appointment& rhs){
    this->desc = new char[strlen(rhs.desc) + 1];
    strcpy(this->desc, rhs.desc);
    strcpy(this->start, rhs.start);
    strcpy(this->end, rhs.end);
}

void Appointment::free(){
    delete[] this->desc;
    this->desc = nullptr;
}
