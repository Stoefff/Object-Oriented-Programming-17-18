#include "Figure.h"
#include "Color.h"
#include <cstring>

Figure::Figure(Point center, Color color)
    :center(center)
    ,color(color)
{}

Figure::~Figure(){
}

void Figure::translate(int horizontal, int vertical){
	center.translate(horizontal, vertical);
}
