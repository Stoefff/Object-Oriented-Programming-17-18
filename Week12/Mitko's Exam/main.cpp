#include <iostream>
#include <string.h>

using namespace std;

struct Student {
    char* name;
    int EGN;
    float averageMark;
};

int main(){
    Student a;
    char* temp = new char[strlen("Dimitur Ivanov Grigorov") + 1 ];
    strcpy(temp, "Dimitur Ivanov Grigorov");
    a.name = temp;
    a.EGN = 1234567890;
    a.averageMark = 6.00;

    cout << "Student name = " << a.name << endl;
    cout << "Student EGN = " << a.EGN << endl;
    cout << "Student average mark = " << a.averageMark << endl;

    delete[] a.name;

    return 0;
}
