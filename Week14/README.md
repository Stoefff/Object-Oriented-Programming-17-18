### Niki's lecture - 30.05.18

### About the HW4
One class, which has a array? template polinoms. We don't care about the x  
Good to have 3 - 4 classes - Polinom, Iterators(both template classes), ... , ...

## Templates
A class with templates variable, have the ability to change the type of the
variables - they could be of type `int`, `float`, `double`  
```C++
template <typename T>
template <class T>
T max(T a, T b){
    return (a>b)? a : b;
}
max<int>(1,2);
max<float>(1.5, 2.5);

Human h1, h2;
max<Human>(h1, h2) // But here class Human should have redefined operators > , =
```

### Similar to macros
```c++
#define max(a, b) ((a>b)? a : b)
```

### Differences to macros
* macros does not have a type checking
* Templates are restring even the variable to be of a certain type(in most
cases the parameter to be of the same type)

### Templates are actually meta-programming
* Templates are not runnable code
* It is a plan for generating code for every type that the function is called with
* The code of the function is generated for every type, that is called for
* If if the function is not called, the function won't even be compiled
* They are compile time, not runtime

### Direct instance
Implementing the template for a certain type. It is useful when we have a difference
in the logic of the function e.g. when using `virtual` functions

## Template classes
```c++
template <template T>
class DynArr {
private:
    size_t size;
    size_t cap;
    T* arr;
public:
    DynArr();
}
int main(){
    DynArr<int> arr;
}
```

### The Visual Studio compiler return very strange mistakes
* They are usually linker mistakes
* Always write the implementation of templates in the header, because in the `.cpp`
the code should be compiled when linking and that is never true

### Template trick
```c++
template <typename T>
DynArr<T>::DynArr();
```

### Tips about HW3
So actually, it was not so good to have all the logic in the types of Users  
Problem will be resolved if User container accepts only objects of type Users,
not just char*

### Better way of handling commands
```c++
line = cin.get(line);
actor = strtok(line, " ");
action = strtok(NULL, " ");
subject = strtok(NULL, " ");
text = strtok(NULL, "\0");
```
## Iterators
Used with templates to have ultimate iterating logic. Its meaning is to have
a universal iterators for every possible type of the template class. For example
for every possible data structure, which is a template type in the `stl`, there
is universal iterator

### How to write iterators: 2 ways
* The iterator is a class in the class it is iterating
```c++
class DynArr{
public:
    class Iterator{

    };
};
DynArr arr;
DynArr::Iterator it;
it = arr.begin(); // return the first object
if (it == arr.end()){
    //There is no more to iterate;
}
```
* The iterator is out of the class, but then the iterator does not have access
to the object it is iterating, and we should write getters/setters;

### Types of iterators
* Constant iterators - does not change anything in the class
* Not constant iterator - could change something in the class

### Some details about iterators
* The iterators should have the pointer to the the object, so it could return
the object it is iterating to
* Defining iterators to good to be like the `stl` convention and have these
operators redefined in the class:
** `++` - so it could iterate, but should count the size in order not to surpass it
** `--`- same like ^
** `=` - so it could change data
** `==` - so it could compare data`

### Armqnov lecture - 31.05.18

### About Exam 2
It's main focus will be Inheritance, Polimorphism.  
There will be the an operator or two to be redefined.  
There won't be

### Redefining operators in the class vs. out of the class
When the arguments are equal, it is good the operator to be redefined out of the
class. When they are or **the operator will use intensively the variables of the
class** - it is good to be in the class

## Templates

### Strongly typed coding languages - pros
It is very good for fast execution - because the processor actually uses many
of the types in c++ for example. The compiler knows this and optimizes the code
for the every certain type that is called and used. This

### Macros - smart replacing the source by the preprocessor!
Macros just substitute code code in the place where the macros is called. They
are also not smart - it could fuck up when we use operators for the arguments
where the macros is called
```c++
#defined min(x, y) x < y ? x : y
min(x++, y++); //Here it is fucked
```

### Using #define
So when we define a new type - `#define int myType` and write a function like
this:

**If there 2 function min() - one int and one template - the compiler will
always use the statically typed**

### Resolving casts in the templates
So we could use templates like this - `min(1, 2)`, `min(1, 2.5)`, but there are
type mismatches, which causes hidden casts, which are something bad in some cases.
For e.g. when we uses classes there could be hidden **implicit** cast and in the
most cases the variable is not correct. As we know there is only 1 implicit cast
allowed in a operation. Two are not allowed. So in this case is good to use
`explicit` in the class

### Best way to resolve the casts
The normal way to use templates: `min<int, int>(2, 3)`

### Biggest problem of templates
Because the template is not compilable alone, all there errors in it could not be
tested **unless the template is called for the needed type**

**Is is not good to use the just `T` for a typename**

**More than one template types are allowed - `template <typename T, typename Size>`**

### `typename` vs `class`
Actually there are all the same, but it is good to use them for convention

**Modern C++ design - very good read but heavy for modern c++ templates**

### C++ templates are a beast
Only in c++ there are templates, because c++ templates != java, c# generics and
also templates > java, c#

### More performance problems
We have a function:
```c++
template <typename T, typename sizeType>
T min(T* arr, sizeType size);

int arr[100];
size_t size = 5;
cout << min(arr, 5);
cout << min(arr, size);
```
So here we have a hidden type mismatch and the function will be generated 2 times  
This will make big projects compile 30 min instead of 15 min, which is very
problematic. How do we solved this -

### Template good practices
If we could not use a certain function/constructor of a template type/class, we
should not use it because it creates restriction - for every passed type, they
should be defined. For example

### More details:
We could specify the return type if there it is a template type
```c++
min<int, int, int>(1, 2)
X min(A a, B b){
    return a < b ? a : b;
    // This could not compile, because the trinary operator could mismatch error
    return a < b ? X(a) : X(b); // Solution - there should be copy constructor
    return a < b ? (X)a : (X)b;// In ^ if there is no cpy constructor a cast
    // is tried like this ^^
}
```

### Class templates
Like template function

### Cast problems and `explicit`
```c++
template <typename Type>
class Array {
public:
    Array():Array(10){}
    explicit Array(size_t cap);
    Array(const Array& rhs);
    // in this namespace the type Class is defined here so we should not use
    //Array<type> and we should just use Array
    void app(const Type& elem);
    ~Array(){delete[] arr;}
private:
    Type* arr
    size_t size, cap;
}
```
In the other cpp
```c++
// In this namespace there is n
template <typename Type>
Array<type>::Array(size_t cap){
    this->cap = cap;
    this->size = 0;
    arr = new Type[cap];
}
```

### Linkage problems - gcc vs visual c++ vs clang

### include "array.imp"

### `inline`
* replaces definition with definition and implementation
* include safe

### Vasi's and Paco's practice

### Redefining operators

### Operator +=
```c++
X& operator += (const X& y){
    this->x.age += y.age;
    return * this;
}
```

### Operator +
```c++
X operator+(const X& y){
    return X(*this) += y;
    //Unnamed object - only 1 copy of it
}

X operator+(const X& y){
    X temp (* this);
    temp += y;
    return temp;
    //Named object - 2 copies
}
```
### Operator <<
```c++
class X {
private:
    int age;
public:
    friend std::ostream& operator<<(std::ostream& out, const X& x){
        out << x.age;
        return out;
    }
}
```
**Not good to use getter and setters, because it fucks up encapsulation**

**Very good resources in the Vanaka's repository"
