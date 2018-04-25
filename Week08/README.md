### Seminar - 11.04.18

### Keyword `finally`
* Not present in c++
* Like a destructor for try/catch blocks

## Error handling

### Throwing error with `exit(1)`

### `ERRNO`
Macros which we set the number with what the error is: `errno = 32;`  
We can see the error massage with `strerr(errno);`  
More basic and fast than exceptions  

### `pair`
Like a `ERRNO` but more like a function: `(result, err)`  
Used in more modern languages like Python  

### `maybe` and `promise`

## `friend` functions
Make functions(and class or its methods) outside some class could access the
private data of this class  
It is not good to use! because it fucks encapsulations  
Only good use case is when redefinition operators
```c++
//class A {
private:
    //
public:
    friend void f();
}
```

## Inheritance
```c++
//class Enemy{
public:
    char* name;
    int health;
    int damage;
    void Attack();
    Enemy(char* name);
}

Class Archer: public Enemy{

}

Class Warrior: public Enemy{

}

Archer::Archer(char* n)
    :Enemy(n)
```
* Base class - is inherited
* Derived class - that inherits

### Inheritance with G4
Inheritance doesn't inherit G4 - for the base variables the constructor of
the base class is called. For the new not inherited things the constructor
of the derived class is called  
Always the constructor of the base class is called, then the one of the derived
class, because the derived object could depend of the bases' data  

The exactly opposite happens with destructor-s: we should always delete the
memory of the derived class, then the base ones. The same order happens when
calling the destructor in the derived class. This happens because of the same
r as dynamic 2D arrays - possible memory leak if we delete first main pointer

### Why the `public` in the syntax
Access modifier - says what type the Inherited will be in the derived class  
**The table of access modifiers could be found in course repository**

### Armqnov lecture - 12.04.18

### How `new` works (same mechanism with arrays)
* Allocates memory
* Creates object in memory with **constructor**

### How `delete` works (same mechanism with arrays)
1. Ask the OS for size
2. Saves the size
3. Call a destructor
4. Frees memory

### Delete in dept
`Delete` knows now many thing to free with help of `[]`  
Just `delete` is much faster than `delete[]` because step 1. is missed  

## Exceptions and breaking the program

### Using exit
By convention used when exiting the program successfully

### Using abort
Used when there is an emergency and it should be terminated
Leaves data not freed

### Exceptions
* Used to handle unwanted behavior
* They are a structure?
* Very nice :smile: :cancer:
* Could be redefined

### Try/catch blocks
Used to `try` a block of code and `catch` any throw exceptions in it
Some useful features:
* Nested passing from the bottom to the top in the stack
* Could catch a `throw "An exception"; `with `catch(const char* msg)` and it
passes the const char* so it could be cout-ed
* Always use `catch(...) { throw; }` to pass the exception above in the stack

**Destructor should never throw exceptions**

**C++ std method**

### Practicum - 16.04.18

### Why we use `&` when catching exceptions
We use in order not to copy memory constantly

**Exceptions are a class**

### Custom exceptions
* They inherit some of the main exceptions types
* Could have some use cases

**`Fitness() = delete[]` blocks default constructor**

### Using unnamed vs. named object to initialize the next object in array
* Using name(with `Car temp(...)`) and then using `=` to define it is very slow
because this thing calls 2 constructors and 2 copy constructors
* Using unnamed object like `array[i] = Car(...)` is optimized to use just one
constructor to do the same work

### `assert()`
If the assert condition fails, the program have failed **Logically in `OUR` code**
somewhere and we should handle the error somewhere. It is a warranty of the
validity of the code, and system
* Used for debugging
* Used only in `Debug` mode and **NOT** in `Release` mode - it is deleted there
* We should not use it on public functions, because the logic of the assert is
to debug OUR code, and not public code
```c++
class Student{
private:
    char* name;
public:
    void print(){
        assert(name != NULL);
        std::cout << name << std::endl;
    }
};
```

### Good trick to set debug messages
`assert("Valid messages" && x*x = y)` - when this fails we can see the text
