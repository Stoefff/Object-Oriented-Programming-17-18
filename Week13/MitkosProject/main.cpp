#include <iostream>
#include "Complex.h"

int main() {

    Complex num1 (4, 6);
    Complex num2 (2, 3);

    Complex temp = -num1;
    temp.printNumber();

    temp = num1 + num2;
    temp.printNumber();

    temp = num1 - num2;
    temp.printNumber();

    temp = num1 * num2;
    temp.printNumber();

    temp = num1 / num2;
    temp.printNumber();

    temp = num1 + 2;
    temp.printNumber();

    temp = num1 - 2;
    temp.printNumber();

    temp = num1 * 2;
    temp.printNumber();

    temp = num1 / 2;
    temp.printNumber();


    return 0;
}
