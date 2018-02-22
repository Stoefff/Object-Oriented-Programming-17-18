## Niki's practical exercise - 21.02.08  
### Method of grading
#### Semester
1. 4 Homeworks - 20% of final  
2. 2 Exams - 10% weight of final  
3. 1 Project - 30% of final  
**50% for 3 on exams for the above**

#### Session
1. Theory exam - 25% of final  
2. Practical exam - 15% of final
**40% for 3 on the above**

### Structures
**The following things are in common between c and c++**
There is 1 major difference between structs in c and c++
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
    s -> age // same the the above row

    Student * pS = new Student;
    pS -> grade = 6 ;
    ps -> name = new char[size];

    //strncpy - say how many symbols to copy, 3-rd argument
    strncpy(ps -> name, "Pesho", strlen("Pesho"));
}
```
Structures are consistent(posledovatelna) in the memory meaning all of its
local variables are one after another in the memory

Object are a type of variable, which means all of its features are preserved

Structures have memory leaks problems just like a dym arr of dym arr

There are anonymous structures in c++ - structures without names

```c++
typedef struct{
    char * name;
    int grade;

} Student;
This way c++ deals with c struct Student s1;
```
Why 32 bits processors use only 4GB of ram?
Because 32 bits processors have a "word" of 4 byte;
This means a pointer in the memory is 4 bytes or as unsigned int or 4 billions
This means 4 billions max addresses in the memory

Because most processors today are 64 bits - there is something called alignment  
**Check how alignment works and why(short answer because of the processors word)**
Which leaves some memory after the vars at the consistent memory of the struct
And we should the most biggest in terms of memory vars at beginning to the lowest
```c++
struct A {
    int a;
    char c;
    int d;
    int * e
};
```
There are nest structures, what a cancer:
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
Gets the longed in terms of memory var and allocates that much memory
And every type writes in this memory
Used for IP addresses octets representation - **Genuis**
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
        A un;
        mg.c = 42;
}
```
### Enumerations(emuns)
```c++
enum Month{
    january = 1;
    april = 42;
}
```
## Armqnov notes 22.02.18
### 
