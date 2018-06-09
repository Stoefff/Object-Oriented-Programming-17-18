#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(Point xy, Color recColor, int recWidth, int recHeight)
	      : Figure(xy, recColor)
		  , width(recWidth)
		  , height(recHeight)
{}

Rectangle::~Rectangle()
{}

void Rectangle::print() const{
	cout << "Rectangle = "
		<< center.getX() << " "
		<< center.getY() << " "
		<< width << " "
		<< height << endl;
	printColor(color);
}

void Rectangle::printPerimeter() const {
	cout << "Rectangle's perimeter = " << 2 * height + 2 * width << endl;
}

void Rectangle::printArea() const {
	cout << "Rectangle's area = " << height * width << endl;
}
