#ifndef __STUDENT__HEADER__INCLUDED
#define __STUDENT__HEADER__INCLUDED

#include <iostream>
#include <string.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

//my enum
//enum Courses {first = 1 , second, third, fourth};

/* Tricky enum
enum Courses {
Math, // 0
Informatics = -1, // -1
Computer_Science // 0
};
*/

// Convention is to write in CAPS
enum Courses {
    INVALID = -1,

    MATH,
    INFORMATICS,
    COMPUTER_SCIENCE,

    COURSE_COUNT
};

const char* courses[] = { "MATH", "INFORMATICS", "COMPUTER_SCIENCE"};
//cout << courses[MATH]; - Ingenious

const size_t maxNameSize = 127;

struct Student {
    char name[maxNameSize];
    Courses course;
    unsigned short age;
    unsigned int facultyNumber;
};


void getStudent(const Student & student){
    cout << student.name << ", "
        << courses[student.course] << ", "
        << student.age << ", "
        << student.facultyNumber
        << endl;
}

//Magic getData, or just save getline for the name
void readData(char data[], size_t size){
    while(cin && isspace(cin.peek()))
        cin.ignore();
    cin.getline(data, size);
    if(cin.fail()){
        cin.clear();
        while(cin && '\n' != cin.get());
    }
    cin.clear();
}

Courses setCourse(const char * course){
    for(int i = 0; i < COURSE_COUNT; i++){
        if (!strcasecmp(course, courses[i])){
            return (Courses)i;
        }
    }
    return INVALID;
}

void setStudent(Student & student){
    readData(student.name, maxNameSize);
    char buffer[32];
    cin >> buffer
        >> student.age
        >> student.facultyNumber;
    student.course = setCourse(buffer);
}

Student* allocateStudents(const size_t & size){
    Student* students = new (std::nothrow) Student[size];
    if(!students){
        std::cerr << "Alocationg failure!!!";
        return nullptr;
    }
    return students;
}

void getStudents(const Student* students, const size_t & size){
    for(int i = 0; i < size; i++){
        getStudent(students[i]);
    }
}

void setStudents(Student* students, const size_t & size){
    for(int i = 0; i < size; i++){
        setStudent(students[i]);
    }
}

void serializeStudents(const Student * students, const size_t & size, const char* filename){
    ofstream file (filename, ios::out | ios::trunc | ios::binary);
    if(!file.good()){
        std::cerr << "File stream failed!!!";
        return;
    }
    file.write((char *)(&size), sizeof(size));
    for(int i = 0; i < size; i++){
        file.write((const char *)(&students[i]), sizeof(Student));
    }
    file.close();
}

void deserializeStundents(Student* & students, size_t & size, const char* filename){
    std::ifstream file (filename, ios::in | ios::binary);
    if (!file.good()){
        std::cerr << "File stream failed !!!";
        return;
    }

    file.read((char*)(&size), sizeof(int));

    students = allocateStudents(size);

    for (int i = 0; i < size; i++){
        file.read((char*)(&students[i]), sizeof(Student));
    }
    file.close();
}

#endif
