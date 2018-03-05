## Niki's seminar - 21.02.08  
### Method of grading
Grading will be focused even more on good code, and not pure functionality
#### Semester
1. 4 Homeworks - `20%`
2. 2 Exams - `10%`  
3. 1 Project - `30%`  
**40% on exams and 50 % on homeworks for 3 for the above**

#### Session
1. Theory exam - `15%`
2. Practical exam - `25%`  
There will be a homework defense which could take or give points  
We chose one of the homeworks and they give us a task from it
**40% for 3 on the above**

### Structures
**The following things are in common between c and c++**  
**There is 1 major difference between structures in c and c++**  
Simplified definition: `many data types in the same place in the memory`
```c++
//Convention is that structures are written with caps case
struct Student{
    int age;
    char * name;
    int grade;
} s1; //Same as written on the next line student s1, but this is global var(bad)

const int size = 32;

void printStudent(Student s){}

void printStudent(const Student & s){} // const & - to touch the struct

int main(){
    student s; // student is type, s is an object
    // struct student s; - in c

    s.age = 42 //s.age is from the type int

    print(s);

    student * s = new Student;
    * (s.get) // s is pointer not object meaning invalid
    (* s).age // getting the age
    s -> age // **Almost** same the the above row
    //"." and "->" have the same priority

    Student * pS = new Student;
    pS -> grade = 6 ;
    ps -> name = new char[size];

    //strncpy - say how many symbols to copy, 3-rd argument
    strncpy(ps -> name, "Pesho", strlen("Pesho"));
}
```
Structures are consecutive in the memory meaning all of its local variables are
one after another in the memory  

Dots are used to call a certain variable from the structure  

Object are a type of variable, which means all of its features are preserved
(In the case of structures???)

Structures have memory leaks problems just like a dynamic array of dynamic array  

There are anonymous structures in c++ - structures without names  

```c++
typedef struct{
    char * name;
    int grade;

} Student;
This way c++ deals with c struct Student s1;
```
**Why 32 bits processors use only 4GB of ram?**  
Because 32 bits processors have a "word" of 4 byte  
=> a pointer in the memory is 4 bytes or as unsigned int or 4 billions  
=> 4 billions max addresses in the memory  

Because most processors today are 64 bits - there is something called `alignment`  
**Check how alignment works and why(short answer because of the processors word)**  

Which leaves some memory after the vars at the consistent memory of the struct  
**And we should use the biggest in terms of memory vars at beginning to the lowest**  
```c++
struct A {
    int a;
    char c;
    int d;
    int * e
};
```
There are nested structures, what a cancer xD:  
```c++
struct A {
    int a;
    bool b;
    long c;
    struct {
        int * a;
        bool b;
    } d;
}
myObj.d.a;
```
### Typedefs
Very useful when calling functions with arg a functions with its own arguments

### Unions
Chooses the longest in terms of memory var and allocates memory with its size  
And every type writes in this memory  
Used for IP addresses octets representation **Genuis!**
```c++
union A{
    int a;
    int b;
    long long c;
};

union IP{
    int addr;
    unsinged char repr[4];
} // the for elements of the arrays are populated with octets of the IP

int main(){
        A mg;
        mg.c = 42;
}
```
### Enumerations(enums)
```c++
enum Month{
    january = 1;
    april = 42;
}
```
## Armqnov lecture notes - 22.02.18
### "&" VS " * "
Both lead to some memory
#### Difference
1. & is constant, * is not constant  
2. * could be NULL, & could not be NULL  

### Some tips and tricks for OOP design
* We should always consider the probable lifetime of the code your writing  
* We should try to find problems as early as possible, best case is in hear xD  
* Good written code means good scaling of the code, or less headache when adding
thins or solving small bugs
* There are 4 good practices for highly scalable / good written code:  
1. **Encapsulation and Abstraction**  
When good abstraction is present you can solve one bug present in multiple child
classes/functions/code with changing only one time the code of the mother
instead of many times at all children
2. **Having knowledge of the code**
3. **???**

### Practicum - 26.02.18
#### `exampleN.cpp` contain interesting uses cases
When we a structure named Student, we have a object form type Student  
Just like `class`  

Structures could have default values, but it is not a good practice  

When we have dynamically allocated string in object, we count make another
copy of the struct which has a pointer which leads to the same memory  
Therefore there is problem if we try to delete that memory 2 times in the copy
and with out
#### Another use case of unions:  
The see the representation of float numbers  
```c++
union Num{
    int num;
    float numL;
}
```
