#ifndef __PERSON__HEADER
#define __PERSON__HEADER

typedef long unsigned int uint;

class Person{
public:
    Person(const char*,  uint);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    void print() const;

private:
    void copy(const Person&);
    void free();

private:
    char* name;
    long unsigned int date;
};

#endif
