#include "Egg.h"
#include <string.h>

using std::cerr;
using std::endl;

Egg::Egg()
    :name(nullptr)
    ,size(0)
{}

Egg::Egg(char* name) :size(strlen(name) + 1)
{
    this->name = new char(strlen(name) + 1);
    strcpy(this->name, name);
}

Egg::Egg(const Egg& other):size(other.size){
    this->name = new char(strlen(other.name));
    strcpy(this->name, other.name);
}

Egg& Egg::operator=(const Egg& other){
    if(this != &other){
        freeMemory();
        this->name = new char(strlen(other.name));
        strcpy(this->name, other.name);
        this->size = other.size;
    }
    return *this;
}

Egg::~Egg(){
    freeMemory();
}

void Egg::freeMemory(){
    delete[] name;
    name = nullptr;
}

void  Egg::setName(char* name){
    freeMemory();
    this->name = new char(strlen(name) + 1);
    strcpy(this->name, name);
    this->size = strlen(name) + 1;
}

char* Egg::getName(){
    return this->name;
}

bool Egg::serialize(ofstream& ofstr){
    ofstr.write((char*)&size, sizeof(size));
    if(!ofstr.good()){
        cerr << "An error has occured while serializing to the file" << endl;
        return false;
    }
    ofstr.write((char*)&name, size);
    if(!ofstr.good()){
        cerr << "An error has occured while serializing to the file" << endl;
        return false;
    }
    return true;
}

bool Egg::
