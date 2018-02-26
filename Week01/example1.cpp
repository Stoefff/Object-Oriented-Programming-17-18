#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Student{
    char name[34];
    unsigned short fn;
};

struct Teacher{
    char name[31];
    unsigned short fn;
};

struct Student1{
        char * name;
        unsigned short fn;
};

int main(){

    Student a = {"Paco", 45212};
    Student* paco = &a;

    cout << (*paco).name << endl; // Because of priority we should have (*paco)
    // Otherwise it wont work

    Student * group = new Student[10];
    group[1].fn = 45321;
    delete[] group;

    //Allignment issues: both Teacher and Student have the same length
    //Because of the processors word which is 4 bytes(in my PC case)
    //So the memory is filled to a number % 34 = 0;

    Student juli;
    Teacher misho;

    cout << sizeof(juli) << " = " << sizeof(misho) << endl;
    //Equal because of memory alignment

    Student1 ginger;
    ginger.name = new char[65];
    cout << *ginger.name; // SERIALIZE the name or gives us the value not the pointer
    
    delete[] ginger.name;


    return 0;
}
