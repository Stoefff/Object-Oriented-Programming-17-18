#include <iostream>

class SmartPointer {
private:
    int *ptr;
    int size;
public:
    explicit SmartPointer(int *iPtr, int size = 0);
    int* getPtr();
    int getSize();
    ~SmartPointer();
};

SmartPointer::SmartPointer(int * iPtr, int size)
    :ptr(iPtr),
    size(size) {}

// For arrays
SmartPointer::~SmartPointer(){
    delete[] ptr;
}

int* SmartPointer::getPtr (){
    return ptr;
}

int SmartPointer::getSize(){
    return size;
}

int main(){
    if(1 == 1){
        SmartPointer p(new int[20], 20);
    }

    return 0;
}
