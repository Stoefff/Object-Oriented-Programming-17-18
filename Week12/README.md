### Niki's seminar - 09.05.18

### Notes about Homework 2
So instead of just adding symbols on the moment, we keep a enum about if a word
is italic, bold and combined. This way we don't have t resize the whole line.
This happens before serializing

## Niki's advice
### Test your program
Even if your programs seems perfect, try to break it This is very important.  
For example, see what happens when you `cin` a string, instead of integer, seem
what happens and fix it.

### Searching for memory leaks
[Use Valgring](http://valgrind.org/)

### Use command line arguments whenever you can
Otherwise Armoqnov knack(цака) :laughing:

### Triangle of software development
It contains 3 vertices:
* Readability
* Speed
* Target

### Main use-case of exceptions is to use them in constructors
Because constructors can not `return` we can't exit them legally. So if we catch
a problem there we should use exception, not just normal `if`s because, usually
in the constructor we dynamically allocate memory, and when failure of constructor
happens we should delete this already allocated memory or call the destructor of
this object, which does the same. So this happens automatically when we use
exceptions, which saves us a lot of time and code.

## Redefining operators
```c++
class Complex{
private:
        double x, y;
public:
        Complex operator+(Const Complex& rhs) const{ // no & because we return a copy
            Complex temp;
            temp.x = this.x + rhs.x;
            temp.y = this.y + rhs.y;
            return temp;
        }
}

int main(){
    Complex a;
    Complex b;
    Complex c;
    c = a + b;
}
```

### Great thins about redefining operators is re-usage of them
So if we have defined operator `+=` about a class, we can and should use it
to redefine other operators which it.
```c++
class Complex{
private:
        double x, y;
public:
        Complex(const Complex& rhs);
        Complex operator += (const Complex& a );
        Complex operator+(const Complex& a) const {
            Complex temp(* this);
            temp += a;
            return temp;
        }
}
```

### Redefining prefix and postfix operators
**Very mind fuck - research yourself**
* prefix operator - ++a

* postfix operator - a++

### Armqnov lecture - 10.05.18

### About exams, homeworks and projects
So in the projects we could use a certain lib that is not usually allowed like
`String`, but if there a problems with usage of it, Armqnov will test if we know
the implementation the lib, like deleting the `#include <string>` and seeing if
we know how to implement it for 30 min. :trollface:

## Multiple inheritance
* When a class has(inherits) multiple interfaces
* Not c++ programmers find multiple inheritance very evil, because it brings us
a lot of problems, but c++ does not fear problems(because it just passes the
problems to us for solving)
* Example - if we have 1 `Base`, 2 `Der` of the Base and:
```c++
class Base{
public:
    Base(int x): x(x){}
    void f() const{
        cout << x;
    }
private:
    int x;
}
Class Der2: public Base{
public:
    Der2(): Base(2){}
}
class Der6: public Base{
    // The same
}
class Main: public Der1, public Der2{

}
int main(){
    Main* p;
    Der1* x = p;
    Der2* y = p;
}
```
So in the memory, Main has an instance of `Der1` somewhere in its memory, and
instance of `Der2` but in other place in its memory. So x and y lead to **Different**
places in the memory of p;

### Casting to children is VERY dangerous
`Der1* ptr = (Main*)y;`

### Problems with the example above
If in the main() we do:
```c++
    Main p;
    p.f();
    p.Der6::f(); // 1
    p.Der6::Base::f(); // 2
```
* 1 is when you want to call `f()` of `Der6`
* 2 is when you want to call `f()` of `Base`

### Small not important details
```c++
class D: public A, public B{};
```
When constructing D, the compiler always constructs first A, then B

### Virtual function in the the diamond inheritance hierarchy
If one of the the `Der1` classes has a `f()` and `Der2` have a `virtual f()`, the
`f()` of main is also virtual

### The simplest diamond inheritance problem
* class `Base`
* class `Derived` - inherits `Base`
* class `Main` - inherits both `Derived and Base`

### Good use case of multiple inheritance:
We an inherited object has 2 use cases, depending on context
* Base class `Vehicle` with a variable `speed`
* Derived class `Boat`
* Derived class `Plane`
* Main class `Hydroplane` (HP)


### Another use case IMPORTANT -
* class `Person`
* class `Student`
* class `Programmer`
* class `fmiStudent`
```c++
fmiStudent p("Pesho","Informatics","FMI");
Student* s = &p;
s->setName ("Gosho");
```
So in this case have changed the name of the object for the Student, but not
the name of the programmer. This is the main problem of the diamond problem -
**inconsistency of data**

### Virtual classes and virtual inheritance - very slow to use
```c++
class Person{

};
class Student: virtual public Person{

};
class Programmer: virtual public Person{

};
class fmiStudent: public Student, public Programmer{

};
```
So just like with functions, when we don't use virtual, the an object of Person
is contain in both Student and Programmer, meaning there are 2 instances in the
fmiStudent of Person, if we use virtual class, instead of an object of type
Person, there is a pointer(or OFFSET) to the person. So in the case above, the
compiler sees that that both Student and Programmer both have a dynamic link to
a Person, the compiler creates an object of person and the passes a pointer(OFFSET)
to it to the Student and Programmer. This solved the problem of the diamond
problem, but this has important details(problem):

### More virtual classes details
So when constructing fmiStudent, we should call the constructor of Student and
Programmer, but both of these classes in their constructor calls for the
constructor of Person. So how do we solved this problem  - We call the constructor
of Person explicitly and not by the constructors of Student or Programmer like:
```c++
fmiStudent::fmiStudent(const char* name ....){
    Person("Sasho");
    Student(124 ,123);
    Programmer("junior", 564);
}
```
**This creates the biggest problems of the multiple inheritance and the virtual
classes (the reason for the hate of this in other language) is that this explicit
calling the the Base constructor BREAKS the encapsulation of the hierarchy, because
every derived class down the hierarchy has responsibility for the Base class and
also it should not even know about this class**

**Virtual classes are slow and if used they require virtual for all of its
potential Derived classes, so this mean to use them as rarely as possible**

### Good use case of the virtual classes: "final" derived class
No body could inherit class F because it is virtual and its derived classes
should call the constructor of B, but only F could call its constructor.
This is called `final` in c++11 and code won't compile if we try to inherit F
```c++
class B{
private:
    B(){}
    friend class F;
};

class F: virtual private B{
public:
    F(){}
};
```
Questions:
1. Does the method with virtual instead of `final` slows the code -
**The compiler optimizes it**
2. Is the whole meaning of B is just to be a guard - **Yes**

### Vasi's and Paco's practice
Actually statically linked functions there are not supposed to be over-ride.  
Dynamically linked functions means the opposite.  
If a function is`virtual` it **IS** `virtual` all the way down if hierarchy. Every class
has its very own `vptr` to a table - which is different for every class and when
we call for a function of the derived class, by the base pointer, it looks in
the table of the derived class, and calls of that functions

**Virtual tables are per class**

### Inheritance details
So we have a `Base` class with variable `name` and we have a `Derived` class that
only inherits, it doesn't add new variable **or adds only static vars**, there
is a trick with the Copy constructor. In this case the copy constructor of the
`Derived` class looks like this:  
`Derived (const Dog& d):Animal(d);`  
**This is automatically optimized by the compiler, meaning this is the default
copy constructor and in this case we should not write other copy constructor**
