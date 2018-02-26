#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

struct Point{
    int x;
    int y;
};
//Try to make code readable for other, using const where we can and & to skip cp
void setValues(Point & a){
    cin >> a.x;
    cin >> a.y;
}

void getValues(const Point & a){
    cout << a.x << " , ";
    cout << a.y << endl;
}

void calcDistance(const Point & a, const Point & b){
    int xDist = a.x - b.x;
    int yDist = a.y - b.y;
    cout << "Distance: " << sqrt( pow( (int)xDist, 2) + (int)pow(yDist, 2))
        << endl;
}

void setArrPoints(Point * arr, const size_t size){
    for(int i = 0; i < size; i++){
        setValues(arr[i]);
    }
}

void getArrPoints(const Point * arr, const size_t size){
    for(int i = 0; i < size; i++){
        getValues(arr[i]);
    }
}
// TODO: Finish it
bool isTriangle(const Point * arr, const size_t size);

int main(){
    Point b;
    Point a;
    size_t size;

    setValues(a);
    getValues(a);

    setValues(b);
    getValues(b);

    calcDistance(a, b);

    cout << "Enter size of array of points: ";
    cin >> size;

    Point * pointArr = new (std::nothrow) Point[size];
    if(!pointArr){
        cout << "Memory allocation fail" << endl;
        return -1;
    }
    setArrPoints(pointArr, size);
    getArrPoints(pointArr, size);

    delete[] pointArr;
}
