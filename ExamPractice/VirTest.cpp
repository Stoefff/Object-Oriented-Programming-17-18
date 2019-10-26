#include <iostream>
using namespace std;

class Base{
public:
    void f(){
        cout << "Base" << endl;
    }
};

class Derived: public Base{
public:
    void f(){
        cout << "Derived" << endl;
    }
};

int main(){
	Derived d;
    Base* ptr = &d;
    ptr->f();
    return 0;
}