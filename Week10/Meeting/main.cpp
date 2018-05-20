#include <iostream>
#include <cstring>
#include "Meeting.h"

using std::cout;
using std::cin;
using std::endl;

void addMeeting(Meeting** schedule, size_t size, size_t capasity){

}

void resize(){}

bool hasAppointmentWith(Meeting** schedule,const char* name, size_t size){
    for(int i = 0; i< size; i++){
        if(!strcmp(name, schedule[i]->getName())){
            return true;
        }
    }
    return false;
}

int main(){

    size_t size = 0;
    size_t capasity = 2;

    Meeting** schedule = new Meeting*[capasity];

    Meeting a("dank memes", "1230", "1330", "Juli");
    size++;
    Meeting b("hello world", "1140", "1450", "Pesho");
    size++;

    schedule[0] = new Meeting(a);
    schedule[1] = new Meeting(b);

    cout << ((hasAppointmentWith(schedule, "Juli", size)) ? "Yes": "No") << endl;

    return 0;
}
