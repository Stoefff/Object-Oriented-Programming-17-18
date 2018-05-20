#ifndef __APPOINTMENT__HEADER
#define __APPOINTMENT__HEADER

#include <iostream>

const size_t maxSizeDate = 8;

class Appointment {
public:
    Appointment(const char*, const char[maxSizeDate], const char[maxSizeDate]);
    Appointment(const Appointment&);
    Appointment& operator=(const Appointment&);
    ~Appointment();

private:
    void free();
    void copy(const Appointment&);

private:
    char* desc;
    char start[maxSizeDate];
    char end[maxSizeDate];
};

#endif
