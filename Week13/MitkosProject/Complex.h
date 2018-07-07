#ifndef __COMPLEX__HEADER
#define __COMPLEX__HEADER

class Complex {
public:
    //Constructor
    Complex(int real, int img);
    //Copy constructor
    Complex(const Complex& rhs);
    //Оператор за присвояване
    Complex& operator=(const Complex& rhs);
    //Destructor
    ~Complex();

    //The defaulty generated copy constr and operator =
    //Work very well, but i will overrite them just to be sure

    void printNumber();

    // Operator for arithmetic negation
    Complex operator-() const;

    // Operators for adding, removing, ...
    // to the current value, thats why it returns
    // the object with амперсант
    Complex& operator+=(const Complex& num);
    Complex& operator-=(const Complex& num);
    Complex& operator*=(const Complex& num);
    Complex& operator/=(const Complex& num);

    //Same operators but with real number
    //Instead of a complex one
    Complex& operator+=(const int& num);
    Complex& operator-=(const int& num);
    Complex& operator*=(const int& num);
    Complex& operator/=(const int& num);

private:
    void copy(const Complex& rhs);

private:
    int real;
    int imag;

};

//single operators +, -, *, /, should be outside the class
//because this operators, do not belong to either of the numbers(objects)
// e.g.: a + b creates new objects which contain the sum of the two
//Thats why it returns "Complex", and not "Complex&", and its not in the class
//Its also const, because "a + b = c" should not be possible
const Complex operator+(const Complex& num1, const Complex& num2);
const Complex operator-(const Complex& num1, const Complex& num2);
const Complex operator*(const Complex& num1, const Complex& num2);
const Complex operator/(const Complex& num1, const Complex& num2);

//Same operators but with a real number as a second argument
//Instead of a complex
const Complex operator+(const Complex& num1, const int& num2);
const Complex operator-(const Complex& num1, const int& num2);
const Complex operator*(const Complex& num1, const int& num2);
const Complex operator/(const Complex& num1, const int& num2);

#endif
