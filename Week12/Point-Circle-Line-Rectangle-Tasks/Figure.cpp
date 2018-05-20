#include "Figure.h"
#include <cstring>

Figure::Figure(Point center, const char* name): center(center)
    ,color(NULL){
    this->color = new char[strlen(name) + 1];
    strcpy (this->color, color);
}

Figure::~Figure(){
    delete[] this->color;
    this->color = nullptr;
}
