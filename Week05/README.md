### Seminar - 21.03.18

### Homework help
Transactions should be done automatically and are made when there is a possible
one. When ever an incomplete transaction is made (someone wants to buy 30 but
there is only 20 on the market) the orders are changed to reflex the money
or wanted

The time will be simulated with the help of the type `time_t` and `time(NULL)`
which gives the the current `timestamp`

## Classes, constructors, destructors
Lifetime of an object: depends on the scope

### Default constructor
So its important to initialize variables with some values, or else the variables
could be initialized with old values which could be a security problem so the
default constructor in not very ok  
Default constructor is not generated when any other constructor is present
```c++
class Student{
    private:
        int age;
        int fn;
        int year;
        char* name;
    public:
        Student(); - default constructor
        // The code of the default constructor
        Student::Student(){
            age = 0;
            ...
            name = nullptr;
        }
}
Student ivan;
ivan.setAge(zz);
```

### Normal constructor
```c++
class Student{
    private:
        int age;
        int fn;
        int year;
        char* name;
    public:
        Student(int age  = 0; int fn = 0); // Could have default values
        // But this ^ is limited because of if we want to pass the fn bu not age
        // its not possible because the value meant for fn is set on age
        Student::Student(int a){
            if(a < 0){
                a = 0;
            }
            age = a;
        }
}
int ageStudent = 42;
Student pesho(ageStudent);
Student juli();
```

#### Default values of normal constructor
Very useful but has a problem:  
Limited usage because of if we want to pass the `fn` bu not `age` its not
possible because the value meant for `fn` is set on `age`

### Static variables
**Shared between every object of the same class**

### Difference between `object.function()` and `Class::function`
* `.function()` - is used on objects and if somewhere in this function there is a
`this` keyword, the `.` operator sets `this` with the object on which the
function is called
* `Class::function` - calls for functions or variables of the class not object


### Encapsulation problem
In the code below we making this complex copy in order not to initialize a new
part of the memory and copies the values instead of just doing `=`. If we use
`=` there are encapsulation issues because:
```c++
class Student(){
    char* name;
public:
    Student(const char* _ name);

Student::Student(const char* _ name){
    if(_ name != nullptr){
        int size = strlen(_ name);
        this->name = new char[size + 1];
        strcpy(this->name, _ name);
    }
}
}
```

### Destructor
What the constructor have created and initialized, the destructor will delete
and free  
There is also a default destructor but it only frees the stack memory
```c++
class Student(){
    char* name;
public:
    Student(const char* _ name);
    ~Student();
Student::Student(const char* _ name){
    if(_ name != nullptr){
        int size = strlen(_ name);
        this->name = new char[size + 1];
        strcpy(this->name, _ name);
    }
}
Student::~Student(){
    delete[] name;
}
}
```

### Smart pointers and row pointers
* Row pointers are the one that we use
* Smart pointers handles its memory and we should worry about memory leaks - it
automatically frees itself at the end of the scope its defined

## Armqnov lecture - 22.03.18

### `Static` and `Extern`
**DO NOT USE**  
If static global variable is needed to be used, define it in `.cpp` file, not
into the header because, it is not making sense to be defined it the header file
because the variable lives in the scope in the file in which is defined and the
header file scope is not very clear where is it exactly, where as .cpp file's
scope is known where it is

### `tellp` and `tellg`
Both returns the number of `BYTES` from the start of the file to the:
* `tellp` - write pointer
* `tellg` - read pointer

### seekX - : X E {p , g} - same as the above

**If we both read and write at the same time the compiler use 1 buffer for
both operation, meaning we could fuck it up so we should ALWAYS sync the buffer
for both operation**

### `eerno` usage
This is a global var used for handling errors in the cpp programs with help
of error codes - good for debugging

### The golden principles of OOP programing
* Encapsulation - for security of code design and security of encapsulated info
* Abstraction - for reusing the encapsulated code without risking security
* Re-usage(Inheritance) - so writing the (encapsulated) code so the abstraction (inheritance)
could be used
* Polymorphism -

## Class

### Guardians of the class(galaxy xD)
* `public` - all can access
* `private` - only class methods have access
* `protected` - only class an its child have access

#### Lollipop diagrams:
Cancer way of drawing classes

#### We could define the classes methods outside the definition of the class
The same principle as definition and implementation of methods
```c++
class Student{
private:
    int age;
    float score;
    char* name;
public:
    int getAge() {return age;}
    const char* getName();
    void addAge();
    float getScore();
    void setScore(float)
}

const char* Student::getName(){
    return this->name;
}
int main(){
    Student pesho;
}
```

### `this->`
This is a keyword pointing to the object of class it is defined and used in.
```c++
const char* Student::getName(){
    return this->name;
}
```
Without `this->` name magically returns the name

### Const methods
They are methods that are not changing the state(variables) in the object it used
```c++
class Dankmemes{
public:
    const char* getName() const;
}
```

### Practicum - 26.03.18

## Classes

### G4 - the most important things about classes
* Constructor
* Destructor
* Copy constructor
* `=` operator  

### Why we should always redefine G4:
**These 4 things could possibly fuck up the behavior color when using a dynamic
memory with their default implementations, so we redefine them to handle this problem**

### Copy constructor problems
When we use static (automatic) variable there are no problems, but when we use
dynamic memory the default copy constructor does a shallow copy which fucks up
the dynamic memory

### Shallow coping
If there are 2 objects from the same class and if we do `obj1 = obj2` and in the
objects there are object dynamic memory the shallow copy instead of initializing
new memory and then coping the memory, it just makes a static pointer leading the
old dynamic memory, which double deleting of the same memory of the heap and
this throws exception

## Difference between method and function
* function is just a function xD
* method is a function of class

### Allowed number of constructors and destructors
* constuctor - not defined max
* destructor - just one allowed

### `const int function() const`;
* First `const` says that the function return `const`
* Second `cosnt` says that the function doesn't change the classes variables

### Copy constructor
The copy constructor is called when we define a new object of the same class
and the initialize it with a existing object. Some use cases:
* Use case 1:
```c++
// Class Point is defined
Point p1;  //also defined with set value
Point p2 = p1 // here copy constructor is called
```
* Use case 2: `function(int a, Point p1)` - also calls the copy constructor
* Use case 3: `:o(point)` - this also calls the copy constructor

`Not sure about this here -`
### Initializing list - for constructors
* For `static types` constructor
* **Doing a shallow copy**

### Endless recursion of copying constructor
If we do not use the `&` and `const` in the definition of the copy constructor
it will go into endless recursion, because then the copy constructor will call
another copy constructor and so on. We use const because we should change the
copied object
