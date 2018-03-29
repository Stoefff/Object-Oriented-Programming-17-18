### Niki's seminar - 28.03.18

**Usually G4 is used only on complex classes**

### Dank use cases of constructor
* Used with prime types
```c++
int i(1);
// is same as
int i = 1;
```
* Syntax sugar
```c++
student s("ivan");
student s = "ivan";
```

### Initializing list
It always run before the constructor is used by:
```c++
class Age{
private:
    int age;
public:
    Age();
    Age(int);
    void setAge(int);
}

class Student{
private:
    int age;
public:
    Student();
};

Student::Student: age(1),
```
So the initializing list is very useful and type safe when there is constructor
that calls for other objects constructors

### A mind-fuck thing
This would compile and work  
This is something like a smart cast in c++ and works like this:  
This cast is possible if the class constructor is with one parameter and using
prime types. So if a function which have a parameter of this object recieves
a prime type which can be passed to this constructor, this transformation(cast)
will take place, and act like nothing happened.  
**This cast will happen everywhere int can**
```c++
class MyInt{
private:
    int i;
public:
    MyInt(int);
    getInt();

}

MyInt::MyInt(int i1){
    i = i1;
}

void print(MyInt){
    cout << i.get();
}

int main(){
    int i = 1;
    print(i);
}
```

### `explicit`
Bans this transformation(cast) - the constructor will never be called unless
it is EXPLICITLY called

### Smart Pointer implementation
Check the files!

### Issue when debugging
So when debugging constructor we should use F11(Go into) to deep into instead of
go to next line

## Copy constructor - only in c++
Used for coping one object to another when defining  
We should always define them to do `deep copy` instead of `shallow copy`  
Doesn't return any type
**The copy constructor should always be constant**

### Copy constructor biggest problem:
**Always write `const` and `&` in the definition of copy constructor**  
Do this to avoid endless recursion and to preserve logic of constructor

### Implementation of a deep copy constructor
```c++
Student::Student(const Student& other)
    :age(other.age) { // Not standard!! If a copy constructor on age is defined
    this->age = new char[strlen(other.name) + 1];
    strcpy(this.name, other.name);
    }
```
## Redefining `=` operator on a class
Like a copy constructor but it is not used when defining a class with the same
vars and more like when at a certain time we want to make 2 objects the same

### Very prone to memory leaks
If the object in which we want to copy there are dynamic memory pointers
and we copied it with out calling the destructor for the old variables, a memory
leak is present

### Standard `=` operator implementation
```c++
const Student& operator = (const Student& o);
```

### Trick not to rewrite code for the copy constructor and `=` operator
**Or how to escape `boiler plating`**
```c++
private:
void copy(const Student& s);
const Student& Student::operator=(const Student& other){
    if(this==&other){
        return * this; // return the object directly
    }
    this.age = other.age;// this code could be in the copy function abov
    this.name = new char[strlen(other.name) + 1];
    strcpy(this.name, other.name) //                       this->copy(other);
    return * this;
}
```
### Armqnov lecture - 29.03.18

## Important NOTE:
**`OOP is just like teen sex. Everyone talks about but almost no one is doing
it properly!`** - Armqnov, 2018

## Life cycle, copy constructors and exceptions

### Good class design  
So when designing a class we should always think which of its methods should be
private. In other words we should always think which of its functionality and
data is visible to the rest of the world and implement encapsulation accordingly  
**The same goes for class life cycle - think what data could be messed up when
the class is dead**

### Object life cycle - same as prime variable
Could be:
* Static(&Automatic) - class is created and deleted in a scope
* Global - at the start of the runtime and dies at the end of the program

### Initializing classes
* With constructor
* Dynamic allocation with constructor
* Called in functions by copy, or copy constructor

### `RAII` principle - Resource Acquisition Is Initialization
So to make the code structure more readable and easy to use and understand this
principle is used. The concept is that the classes and objects have responsibility
meaning it should handle the initialization and de-initialization of this data
at the end of the life cycle of the object

### Constructor details:
* Doesn't return a type
* Default constructor is only called when no other constructor are present
* At least 1 constructor is present ALWAYS
* If there is no default constructor, if the passed argument doesn't match one
of the implemented constructors, the code won't compile

### Dynamic allocation of a object:
* Dynamic allocation of a object - `Student* p = new Student(16);`
This calls the constructor with int and allocates the whole object in the heap.  
And after that we should write `delete`
* An array of objects - `Student p[10] = {Student("pesho", 16), Student("juli, 19")};`
* In the example above intermediate anonymous object will be created the then they
will be allocated in the head - not sure about this

### Copy constructor
* The recursion problem the of copy constructor - Always write &
* Always write `const` in the copy constructor
* The default copy constructor is generated when you pass non-matching arguments -
this is **very hidden and problematic thing**  

**`Student(const Student&) = delete;` - says this method(constr) is not allowed**

### `explicit`- disallowing the cast
```c++
void f(Student x);
f(20); //without explicit would work, with it won't
f(Student(20)); // would work with explicit: type-safe
```

### Initializing data
So constructors should handle invalid input:
3 ways of handling:
* Correct the fuck up data
* Mark the fuck up object as a special one - should define a special condition
* Exceptions  
```c++
Student(int age, const char* test){
    if(!test) text = "";
    this.name = new char[strlen(text) + 1];
    strcpy(this->name, text);
    if(!validAge(age)){
        return; //not good
        exit(1); // If an invalid student goes to FMI, ALLAHU AKBAR the whole FMI
    }
    this->age = age;
}
```

### Initializing list
Good use case:
```c++
Student::Student(int age, int dab, const Address a, const char* name)
    :dab(dab)
    ,addr(a)
    ,name(nullptr){
    if(!valid(dab)){
        setName(name);
    }
}
```
