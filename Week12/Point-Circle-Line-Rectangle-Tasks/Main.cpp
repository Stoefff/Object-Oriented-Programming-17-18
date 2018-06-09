#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {

	size_t size = 2; // Count of figures
	Point cicleCenter(1, 2);
	Point rectCenter(3, 4);
	Color color = strToColor("blue");


	Figure** container = new Figure*[size];
	container[0] = new Circle(cicleCenter, color, 3);
	container[1] = new Rectangle(rectCenter, color, 2, 3);

	

 	return 0;
}
