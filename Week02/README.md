### Niki's seminar - 28.02.18
## Files and file systems
**[All the info needed HERE](http://www.cplusplus.com/doc/tutorial/files/)**  
`TODO:` Check flags values!  
**Why we need files? :**  
* Persistence of programs - to store information which can be used even after
* Loading configurations, information, etc,  

Downside of storing in files at the hard disc:  
Very slow because of the hard disc read/write time

### fstream library - lib to handle handle files
* `Ifstream` - input stream from the file to us || just we `read` from the file
* `Ofstream` - output stream from the file to us || just we `write` in the file
* `fstream` - overall  

We can use them to load files, close files

**Types of files interpretation (different way of handling them):**  
* Text
* Binary

### Example for writing to files:
```c++
#include <iostream>
#include <fstream>

int main(){
    std::ofstream file; // var of type file
    file.open("example.txt"); // read from file
    //file.open("example.txt", ios::out | ios::app);
    // There are many flags for open();
    // if open an non existing file - it is created
    file << "File area cool\n"; // << are defined only for text files
    file.close();
    return 0;
}
```

### Example for reading from files
```c++
#include <iostream>
#include <fstream>

int main(){
    std::ifstream file ("example.txt"); // saved us one row of writing same as ^
    // We should always if the opening of a files is valid
    if (! file.good() ){ // there are also bad(), fail(), eof()
        std::cerr << "Could not open files"; // cerr - standart error
        return -1;
    }
    char buff[256];
    // getline return how many symbols are read, return negative num when error
    while (file.getline(buff, 256) ){
        file >> buff;
        std::cout << buff << std::endl; // Catches to space !!
    }
    file.close();
    return 0;
}
```
### Some useful function for iteration pointer:  
The iteration pointer is only one but c++ gives abstraction with 2 pointers:
* tellp - tell us put position
* tellg - tell us get position
* setp - set put position
* setg - set get position
* seekg
* seekp  

**Warning: seek could go after the eof!**

### Text vs. Binary
Text files are preferred because we can see the information  
Binary files are preferred for compactness, but hardly readable

### Binary representation dependence of processors:
* Little Endian - 5432 - is represented as 2345 in the memory (INTEL)
* Big Endian 5432 - is represented as 5432 in the memory

### .h (header file) vs .cpp
* Headers contain just definition
* CPP are the implementation of the function of the header

### Binary files
```c++
files.write((const char *)&pesho, sizeof(pesho))
// (const char*) & is because we use char to represent bytes
// const and & because we read this memory
// without & is object containing the hole info
```
This generates binary, we could not read as .txt  
We could use a reader function to populate a struct from a file  

**`TODO:` Check Vasi's repo from more example code**

### Armqnov lecture - 01.03.18
## Structures
Convention is that objects and vars are written with low case  
Structures and classes are written with CAPS  

Never forgetti `;` after definition of structure   
Default values for structures are a bad thing to do  

Dynamic structures:
```c++
struct Point{
    float x, y;
    int color;
};
Point p1 = {3.2, 7.6, 0}
 Point * p2 = &p1;
 * p3 = new Point; // Without []
p3->x = p3-> = 0; // why -> : Because p3 is pointer not object
p3->color = 0x00FF1010;
```
We could make functions which have arg of type pointer to structure and we
should watch out when we are passing things to this function:
* & to object should work
* passing just the object should fail
* passing pointer to the object is ok, but better use &  

### Memory padding (alignment)
All address are % 4 = 0, so if we allocated memory for a var that is not % 4 = 0
the bytes to the next % 4 = 0 are lost and var in the structure is starting
from there  

Padding is the reason for defining structure vars from the the biggest to the
smallest in terms of memory. Some compilers does this for us even if we failed
to use the convention correctly

Typed of padding:
* Natural padding: the way explained ^ above
* `Pragma` - Selected padding: instead of using the processors step (default 4)
some compilers could set the the number of padding: % n = 0, where n is chosen
from user like a `power of 2`

Use cases of Selected padding:
* Sometimes it could be used to save memory - fast algos use a lot of memory
* Optimization as a whole

### #include < > vs #include " "
* < > used when using external lib: searching in ext lib then local files
* " " a source file from the project: searching in local files then ext libs

**There could be a task with selected padding in the session**

**Passing by value is slow**

### Passing * vs &
* `&` is more easy - working without pointers
* `&` because it is safer - we could be more careless when passing &
* `&` are sometimes slow
* `const &` whenever we can - easily readable and safe for teamwork

```c++
struct Address {...};
Address a = {"Sofia", "6"};
address b = a;// Different from the below
a = b; // Different from the above ^
```

**Warning!!! :**  
Whenever we see a `*` in structure we should always be alarmed and watch out
what happens with pointer and its values - `Many potential memory problems`  

### Byte field
There are created with byte operations  
Possible syntax sugar of bit operations in structures ????  

**Only works with hole number types**
```c++
struct Student {
    char * name;
    unsigned short course: 3; // 3 bit size i memory
    unsigned short sub: 4; //4 bits
    unsigned short : 9; // padding instead of splitting var memory across byte fields
    unsigned short st: 1; // ---//---
    unsigned short stream: 3;
    unsigned short fn;
}
```
**How it works:**  
Uses the first type which is defined with byte field and allocated memory from
one var f this type. Then allocates the byte fields from this type if the next
vars are bite fields from the same type. If its not of the same type makes
allocates again memory and check next vars in the structures. In the some of the
next byte field exceed the current allocated byte
