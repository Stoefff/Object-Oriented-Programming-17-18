#include <iostream>
#include <math.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

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

Point * allocatePointArray(const size_t & size){
    Point * pointArr = new (std::nothrow) Point[size];
    if(!pointArr){
        cout << "Memory allocation fail" << endl;
        return NULL;
    }
    return pointArr;
}

void writePointArray(Point * pointArr, const size_t & size, const char * filename){
    ofstream file (filename, ios::out | ios::trunc);
    if(!file.good()){
        std::cerr << "File stream failed!!!";
        return;
    }
    file << size << '\n';
    for(int i = 0; i < size; i++){
        file << pointArr[i].x << " " << pointArr[i].y << '\n';
    }
    file.close();
}

void readPointArray(Point* & pointArr, size_t & size, const char * filename){
    ifstream file (filename, ios::in);
    if(!file.good()){
        std::cerr << "File stream failed!!!";
        return;
    }

    file >> size;

    pointArr = allocatePointArray(size);

    for(int i = 0; i < size; i++){
        file >> pointArr[i].x >> pointArr[i].y; // Automatically handles whitespaces
    }

    file.close();
}

void serializePointArray(Point* pointArr, const size_t & size, const char * filename){
    ofstream file (filename, ios::out | ios::trunc | ios::binary);
    if(!file.good()){
        std::cerr << "File stream failed!!!";
        return;
    }
    file.write((char *)(&size), sizeof(size));
    for(int i = 0; i < size; i++){
        file.write((const char *)(&pointArr[i]), sizeof(Point));
        //casting is just to divide the data in byte to byte
    }
    file.close();
}

void deserializePointArray(Point* & pointArr, size_t & size, const char * filename){
    std::ifstream file (filename, ios::in | ios::binary);
    if (!file.good()){
        std::cerr << "File stream failed !!!";
        return;
    }

    file.read((char*)(&size), sizeof(size_t));
    // size = fileSize(filename) / sizeof(Point);

    pointArr = allocatePointArray(size);

    for (int i = 0; i < size; i++){
        file.read((char*)(&pointArr[i]), sizeof(Point));
    }
    file.close();

}

int main(){
    size_t size;
    //cout << "Enter size of array of points: ";
    //cin >> size;

    //Point * pointArr = allocatePointArray(size);

    //setArrPoints(pointArr, size);
    //getArrPoints(pointArr, size);

    //writePointArray(pointArr, size, "example.txt");

    //serializePointArray(pointArr, size, "example2.bin");

    Point * pointArr;
    //readPointArray(pointArr, size, "example.txt");
    deserializePointArray(pointArr, size, "example2.bin");
    getArrPoints(pointArr, size);

    delete[] pointArr;
}
