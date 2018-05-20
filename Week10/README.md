### Niki's seminar - 25.04.18

### For projects
* Projects will be very long ~ 2000 lines or more
* We will have to research thing
* We should not just invent things on our own - **Just google it**

### The code for the initializing list i used on the exam is very valid
```c++
class A{
private:
    int i;
    int j;
};

Class B{
private:
    A a;
}

B:B(int i, int j):a(i, j){

}

```
### Pointer of pointer to objects (Class**)
**Not in the sense of array of arrays of objects**  
**The meaning is pointer to pointers which are dynamically allocated objects
without calling default constructor but just creating objects only when valid
data for the objects is passed**
```c++
B** arr = new B* [size];
for(int i = 0; i < size; i++){
    arr[i] = new A(5, 6);
}
```

**`delete[]` objs is calling the destructor of every object**

### Multiple inheritance
We use this when we want to inherit 2 classes instead of one

### Conflicts when we inherit
If we inherit 2 functions with same name there is a problem  
The solution is just to say form which base class is the function we want to call

### `Diamond problem` - for interviews
If we have 2 classes that inherit the same base class, and the their is a forth
class which inherits the 2 already inherited. So if we want to call a function,
which is a present 3 times in this class, we choose which to call by just saying
the functions of which class we want to call.  
Another big problem of this that the memory of the first base class is copied
2 times:
* As a sub member of the second
* As s sub member of the third  
This is a big problem solved with virtual inheritance

### Virtual inheritance
So in the diamond problem discussed above we can inherit the first class just
once by using virtual inheritance. When we write `virtual` we just say that this
class will have only one instance of the first class in the memory, if 2 derived
class are inherited. This is done with the help of virtual tables which contain
the position of the virtual classes in the memory and instead of the whole class
the 2 derived class just have pointers for the most base class.
```c++
class A{

};
class B: public virtual A{

};
class C: public virtual A{

};
class D: public B, public C {

};
```
### Many modern languages allow only one class to be inherited
This problem is solved with abstract classes

### Abstract classes
* Could be inherited many times
* There just plans
* Cant have instances

### Lecture - 26.04.18 - **Missed**

### Vasi's and Paco's practice - 30.04.18

## Inheritance

### C++ inheritance
* public
* protected
* private  

**[Table of access modifiers](https://www.google.bg/search?q=c%2B%2B+inheritance+access+modifier+table&safe=off&source=lnms&tbm=isch&sa=X&ved=0ahUKEwj6t9fS8eHaAhVBBSwKHaajDWoQ_AUICigB#imgrc=JfS5C5wix2XGuM:)**  

### Semantic inheritance
* `is-a` - inheritance
* `has-a` - composition
* `is-implemented-in-terms-of` - private inheritance

**There are very good notes in Vasi's repo**  

### Types of composition
* Normal composition - The bottom class has a object of other class and this
object is responsible for the data of other class object
* Association - not full composition - somewhere in the code we have object of
another class, but it is not a variable of the class - we don not have dependency
between the classes
* Aggregation - We have a object of another class, but is only a pointer to it,
meaning the class is not responsible for the data to which the pointer is leading
to. We are dependent on the data of the class, and this could cause some problems
because 2 objects of this class could have the same pointer, and change in the
one class could lead to unwanted change in the second

### Overriding vs. Overloading 2
* Overloading - difference made in compile time
* Overriding - difference made in runtime  

### Initializing `const` variables in classes - immutable
We initialize const variables with initializing list?

### Initializing `static` variable in classes - reference counting

### What we do when we want to have exactly 10 objects of a class
We use a `static int count` to count the objects.

### If we want to use dynamic array but can not use default constructor
We just do `Class**`
