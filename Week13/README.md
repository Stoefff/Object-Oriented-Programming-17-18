### Niki's seminar - 16.05.18

### Hint about HW3
Some classes are **recommended**, be aware of that, because otherwise the project
will be very long and hard

### `virtual` clone function
So the we can not use the copy constructor as a `virtual` and in order to have
a coping function we do a `virtual clone()`. Usage:  
`new shapes2[i] = shapes1[i]->clone()`  
It is a virtual function that calls the copy constructor of the derived class and
return the pointer to the newly created object as:  
`return new Square(*this);`

## Redefining more complex operators

### All we can want to know about redefining operators:
[Geek for geeks](https://www.geeksforgeeks.org/operator-overloading-c/)
[Stack Overflow](https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading)
[CPP Reference](http://en.cppreference.com/w/cpp/language/operators)

**So in order to sort objects we should redefine operator `>`**

### Boolean operators
* Very prone to reusing, for example `!=` is just `==`. Also `>` is just `!<=`
* The convention is that boolean operators should be written outside that
definition of class, in the same `.h` and `.cpp` file. It is written outside,
because the both sides are equal, so the operator does not belong to one of the
objects.

### Unary operators
`!` - unary operator, returns bool, part of the class definition?

### Operators about comparison - very reusable
The only 2 operators need to redefine all others are `<` and `==`, all others
are could be written with them.

### Operator `==` about class Vectors
```c++
bool operator==(const VEctor& a, const Vector& b){
    return a.x == b.x && a.y == b.y;
}
```
### Redefining byte operators
Not good thing to do, unless we use redefine them for streams

### Stream operators
Actually in `cout << 2`, `<<` is redefined byte operator for class `cout`  
Also when we need to print a class in a file, we should redefine `<<` in order
to do `file << a`

**Always write stream operators outside the defining of the class, because the
class is actually changing things in the fstream class, not in the objects**
```c++
ostream& operator<<(ofstream& out, const Point& p){
    return out << "x: " << p.x << "y: " << p.y;
}
```
**This function should be `friend` of a class Point, because we should do `p.x`**  
**Its ofstream& because we should be able to do `cout << a << b << c;`**  

###Armqnov lecture - 17.05.18 - **missed**

### Vasi's and Paco's Practice
Should have a class FileSystem  
Paco hierarchy:  
![Paco's hierarchy](https://scontent-sof1-1.xx.fbcdn.net/v/t1.15752-9/s2048x2048/33045041_2135545303389675_8098395852923469824_n.jpg?_nc_cat=0&oh=2df2fe71e739f55d5bf8d6c4d9192aa9&oe=5B85DDDF)
