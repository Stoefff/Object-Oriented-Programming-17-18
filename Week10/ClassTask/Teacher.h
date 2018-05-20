#ifndef __TEACHER__HEADER
#define __TEACHER__HEADER

#include "Person.h"

class Teacher: private Person{
private:
    Teacher(const char*, const uint,
            const char*, const char*);
    Teacher(const Teacher&);
    Teacher& operator=(const Teacher&);
    ~Teacher();

    void changeUni(const char*);
    void changeSubject(const char*);

    void print() const;

private:
    void copy(const Teacher&);
    void free();

private:
    char* uniName;
    char* subjectName;

};

#endif
