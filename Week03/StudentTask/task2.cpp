#include <iostream>
#include <math.h>
#include <fstream>
#include "Student.h"


int main(){
    size_t size;
/*
    cout << "Enter number of students: " << endl;
    cin >> size;

    Student* students = allocateStudents(size);

    setStudents(students, size);
    getStudents(students, size);

    serializeStudents(students, size, "studentExample.bin");
*/

    Student* students;
    deserializeStundents(students, size, "studentExample.bin");
    getStudents(students, size);

    return 0;
}
