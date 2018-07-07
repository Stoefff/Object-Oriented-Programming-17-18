#include "Complex.h"
#include <iostream>

using std::cout;
using std::endl;

Complex::Complex(int _real, int _imag){
    real = _real;
    imag = _imag;
}

Complex::Complex(const Complex& rhs){
    copy(rhs);
}

Complex& Complex::operator=(const Complex& rhs){
    //This checks if the addresses of the current object
    //and the passed object are the same
    if(this != & rhs){
        copy(rhs);
    }
    return *this;
}

//No dynamic memory so default destructor is used
Complex::~Complex(){
}

void Complex::copy(const Complex& rhs){
    real = rhs.real;
    imag = rhs.imag;
}

void Complex::printNumber(){
    cout << real;
    if (imag >= 0){
        cout << " +i " << imag;
    } else {
        cout << " -i" << imag;
    }
    cout << endl;
}

Complex Complex::operator-() const{
    return Complex(-real, -imag);
    //Връщаме нов обект, на който е с обратни стойности на числата
}

Complex& Complex::operator+=(const Complex& num){
    real += num.real;
    imag += num.imag;
    return *this;
    // Понеже имаме референция връщаме съшия обект
    // За когото в викнат оператора
}

Complex& Complex::operator-=(const Complex& num){
    real -= num.real;
    imag -= num.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& num){
    real *= num.real;
    imag *= num.imag;
    return *this;
}

Complex& Complex::operator/=(const Complex& num){
    real /= num.real;
    imag /= num.imag;
    return *this;
}

Complex& Complex::operator+=(const int& num){
    real += num;
    return *this;
}

Complex& Complex::operator-=(const int& num){
    real -= num;
    return *this;
}

Complex& Complex::operator*=(const int& num){
    real *= num;
    return *this;
}

Complex& Complex::operator/=(const int& num){
    real /= num;
    return *this;
}

const Complex operator+(const Complex& num1, const Complex& num2){
    return Complex(num1) += num2;
    //Връщаме нов обект, който е със същите стойности като num1
    // Обаче събран с числата на втория подаден обект.
    // Преизползваме оператора += , който сме написали по горе
}

const Complex operator-(const Complex& num1, const Complex& num2){
    return Complex(num1) -= num2;
}

const Complex operator*(const Complex& num1, const Complex& num2){
    return Complex(num1) *= num2;
}

const Complex operator/(const Complex& num1, const Complex& num2){
    return Complex(num1) /= num2;
}

const Complex operator+(const Complex& num1, const int& num2){
    return Complex(num1) += num2;
}

const Complex operator-(const Complex& num1, const int& num2){
    return Complex(num1) -= num2;
}

const Complex operator*(const Complex& num1, const int& num2){
    return Complex(num1) *= num2;
}

const Complex operator/(const Complex& num1, const int& num2){
    return Complex(num1) /= num2;
}
