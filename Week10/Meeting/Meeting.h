#ifndef __MEETING__HEADER
#define __MEETING__HEADER

#include "Appointment.h"

class Meeting: private Appointment {
public:
    Meeting(const char*, const char[maxSizeDate], const char[maxSizeDate], char*);
    Meeting(const Meeting&);
    Meeting& operator=(const Meeting&);
    ~Meeting();

    char* getName() const;

private:
    void free();
    void copy(const Meeting&);

private:
    char* name;
};
#endif
