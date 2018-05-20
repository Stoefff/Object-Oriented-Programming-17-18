### Seminar - 02.05.18

## Virtual functions

```c++
class Base{
    f();
};

class Derived: public Base{
    f();
};

Base b = new Derived;
b->f();//HERE

((Derived*)b)->f(); // here is called the functions of Derived,because we of the cast
```
**HERE calls the function of `Base`, because the pointer is of type `Base`**  

### Virtual functions are not compile time

### Syntax
```c++
class Base{
    virtual f();
};

class Derived: public Base{
    virtual f(); // Here is also virtual, but convention said we should write it also here
};
```

### Virtual pointer - `vptr`
Leading to virtual functions table, which contains the addresses to the all the
functions of some class. A class contains only one `vptr`, is stored in the `Base`
part of the `Derived` class and it lead to to the virtual table of the derived
class. In this case when we have `Base* a = new Derived`, the virtual table will
of the derived, so will be all functions, so polymorphism will be met.

### Static linking
So normal class without virtual. All addresses of the functions in it are
contained in the memory of the class, and this is determined compile time   

### Dynamic linking
So when we use virtual function, we say they are dynamically linked, because
the value of the `vtpr` is set in the `runtime`, because the compiler, does not
know of which derived class the pointer will be. This determined runtime, because
the object is created dynamically(in the runtime) and the compiler apparently
determines of which class is an object, once it is created in the memory.

**There is only 1 `vptr` for the current object, not 2 - one for the `Base` class
and on for the `Derived` class - this is incorrect**

### How does it work
So we are looking in the case above. If we didn't have a virtual in the case above
the `b` pointer searches for the `f()` functions of the `Base` class. It is static
linking of functions, so the compiler sees the address of `f()` of `Base` class
and calls it, because there is no `vptr` and the linking is static. If it was
virtual the compiler does  not see the address of `f()` of `Base`, instead it
searches for a pointer to the virtual table, оr а `vptr`, which leads to the
**virtual table** of the current class.

### The virtual table
The virtual table contains all functions of the class and next to them
their address in the memory.
**The virtual table is per class, not per object**

![image](https://scontent.fsof2-1.fna.fbcdn.net/v/t1.15752-9/32458527_1716645798410998_8413055370460659712_n.jpg?_nc_cat=0&oh=806b9c4bcb90a57fef9fb9bcc468d8e2&oe=5B8A3C68)

### Virtual destructor
Very important, because as in the case above, we could have memory leaks because
actually the destructor is also function
`virtual ~Base()`

**It is not a good practice not to use virtual functions in constructor**

## Polymorphism := one interface, many different objects
So when we have a pointer of a type a `Base` class which leads to many objects
which are **objects of different derived classes**. All of these classes have the
same function. And if we want to call the derived function of every class we should
use the `virtual` functions because the pointer is of type `Base`

### Pure virtual functions
* Makes a class abstract
* Forbids implementation of the function
* Class cannot have objects
* Should always be override
```c++
class Animal{
    virtual void makeSound() = 0;
};
```

### Abstract vs. interface class
* Interface is class only of pure virtual functions
* Abstract could contain both pure virtual and just virtual functions
