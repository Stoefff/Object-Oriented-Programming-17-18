#ifndef __EGG__HEADER__INCLUDED
#define __EGG__HEADER__INCLUDED

#include <iostream>
#include <fstream>

using std::ofstream;

class Egg{
public:
    Egg();
    Egg(char* name);
    Egg(const Egg&);
    Egg& operator=(const Egg&);
    ~Egg();

    char* getName();
    void setName(char*);

    void freeMemory();

    bool serialize(ofstream&);
    bool deserialize(ofstream&);

private:
    char* name;
    size_t size;
};


#endif
