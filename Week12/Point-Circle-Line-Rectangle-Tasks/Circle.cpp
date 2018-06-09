#include <iostream>
#include "Circle.h"

using namespace std;

const float pi = 3.14;

Circle::Circle(Point xy, Color cirColor, int rad)
	:Figure(xy, cirColor)
	,radius(rad)
{}

Circle::~Circle()
{}

void Circle::print() const{
	cout << "Circle "
		<< center.getX() << " "
		<< center.getY() << " "
		<< radius << '\n';
	printColor(color);
}

void Circle::printPerimeter() const{
	cout << "Circles' perimeter = " << 2 * pi * radius << endl;
}

void Circle::printArea() const {
	cout << "Circles' area = " << pi * radius * radius << endl;
}
