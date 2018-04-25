### Niki's seminar - 18.04.18

### Security issues in code
When using err streams or logs we should NOT write many things about the
internal logic or models - **It could become a security issue**

### Dynamic array or `Vector`
* The same in c++
* Very fast because of the linear arrangement in the memory
* The only con is the moment when you should resize, because of the copied memory

## Inheritance (continue)
* Useful when trying to find whether two classes are similar
* Logically can be changed with **inherited `IS` the derived**

### Access modifiers
* public - set the same access modifiers in inherited class as the derived
* protected - you know it ;)
* private - never useful  

### Overriding
Changes implementation  

### Overloading
Does not change implementation

### Overloading vs overriding
**Frequently asked question in interviews**

### Casting inherited classes to derived class
Just gets the derived class data form the inherited
This does not work with array of classes
**This cast could be automatic - big underwater stone xD**

### Casting with pointers
Pointers could treat the same memory like different objects

### Composition
**Has A**
```C++
class A {};
class B{
public:
    A a;
};
```
### Composition vs. inheritance
Another important question for interviews - we should always consider where an
an object `is` another or `has` another class

### Armqnov lecture - 19.04.18

## Namespaces, `static`

### The idea of namespaces
The idea is that we should have conflicts of names when we include a lot of code

### Declaring namespaces
* First way
```c++
namespace eksdi{
    namespace {
        ...
    };
};
```
* Second way
```c++
{
    using std::cin
}
```
**The `using` live only in the scope in which it is declared**  
This is why we globally use `using std::cin` so we have it everywhere  

### `::` - scope operator
Actually all variables are understood by the compiler like that: `::x;`

### Classes actually always declare their namespace
* This is the reason why their is no name conflicts in different classes
* We could access the class namespace(or just methods) with the scope operator

**Namespace could be defined on many places and they sum each other in the
namespace**

### Difference between `math.h` and `cmath`
* `math.h` is the C optimized header
* `cmath` brings the same methods but optimized for C++ - **Use this when possible**

### Friends of a class
If a class has a friend, the friend have full access to the class
* friend are not symmetric unless said explicitly
* friend void B::f();
* friend class C;
* Does not matter where we right it, but we write it at the top by convention

### Const methods
* `int getx() const;` - says that the `this` is a pointer to constant object or
we just say constant `this`
* `const int get();` - const when linking, idk :laughing:

### Static type or method
They are a part of the class and not the object

### Static variables,
All the objects share this same variable. But by convention these variables are
ONLY of type: `static const int x = 7`, otherwise there could be problems when
including, linking and many other things  

**Static variables hide `extern` in them so they could be included properly**

### Static methods
`static int getX();` and we call they **which the class, not the object** like
`A::getX();`

### Class which cant have objects
```c++
class Math{
private:
    Math(const Math&); // this actually blocks all constructors
    // constructor delete; does not work in old standards

public:
    static sqrt(...);
    static pow(...);
};
```
**We should call constructors in constructors**

#### Armqnov showed us some useful cases of the static methods in c++:
* Singleton - released with double encapsulation
* Object counter
* Resource pool

### rhs and lhs object names
* rhs - right hand side - use case when redefining operator= so its clear which
object is as seen as from the `=`
* lhs - left hand side
