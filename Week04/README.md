### Niki's seminar - 14.03.18
## Classes
### The only main difference between class and structure in c++
Structures doesn't have encapsulation by default and all of its variables are
public by default  
Classes have encapsulation by default meaning that all its variables are private
by default  

### Some important OOP principles
1. Simplicity - classes should define only its most basic and logical, the class
should solve one task about the thing its defining `ONLY` - It fucks only with
its information
2. Encapsulation
3. Modularity - the logical and useful polymorphism and also easy adding of  
classes. methods and features to the hierarchy  
4. Decoupling - Classes should not depend on one another  
[This could be useful](https://anampiu.github.io/blog/OOP-principles/)  

**Common mistake is writing the code and not thinking about the OOP design and
its hierarchy**  
Good way of designing the structure of the project is using `UML` diagrams!

### An example for a typical(stupid) class:
```c++
class Comuter{
private:
    CPU intel; //CPU, RAM, ... are classes
    RAM broadcom;
    OS os;
    Parts* perifery;
public:
    bool powerOn();
    int OSUpdate();
    bool playDevice(Device d);
    result runProgram(Pragoram p);
}
``
#### Designing hierarchy
One of the major things when designing the hierarchy of a certain object is to
break the object in certain `USEFUL` way meaning a normal IRL representaion
of the object

#### Using `extern`
So the following problem was met in the `Magic The Gathering` task in `Week03`:  
We should have a global `static` var `ID` in the whole program defined in one of
the .h files. As Niki said when including the fail containing the global var,
it actually creates a new global var with each including. So in order to avoid
it we use `extern` key word so it does not create a new global var  

### Armqnov lecture - 15.03.18

Most of time was wasted: He revisited the last lecture  

#### Stream flags and options:
* .good();
* .bad();  
[All this cancer could be found here](http://www.cplusplus.com/doc/tutorial/files/)  

#### Difference between .open() and .good()
* .open() - checks if the file is opened successfully and does not check if the
buffer is broken
* .good() - check is the file is opened successfully and if the buffer is not
broken after that  

#### Handling broken buffers and streams:
```c++
file >> s[i].name;
if(!file) break;
file>>s[i].age;
while(file.fail() && !file.eof()){
    file.clear();
    file.ignore();
    file >> s[i].age;
}
```

**file.read(...) - returns the file stream**  

#### gcount()
Returns how many bits are being read(/write?) after the last operation

#### tellp()
Returns `streampos` pointing to where is the pointer for writing is

#### tellg()
Return `streampos` pointing to where is the pointer for reading is

#### seekg() and seekp() - sets the pointers for reading and writing
* `seek()` could have flags to:
 * `ios::curr` - starts counting from the current position, adds the given number
from the current position of the pointer  

#### .flush()
It flushes the buffer into the file, meaning it ensures us that the information
in the buffer is written it the file and buffer is now clean and empty  

#### `/n` vs. `std::endl`
* `\n` just add a new line
* `endl` adds a new line and the flushes the buffer

#### Reading an array from a text file
We should be always aware how many bytes are ACTUALLY read because we could want
to read 20 bytes but the stream gives us 10 and we don't know that  
Easy solution for this problem:
```c++

```
**Never seek() or get() in text files**

### Practicum - 19.02.18

### How to read a line from a text file
* std::getline(<stream>, <buffer>)
* file.getline;
* ofstr.write("etg", 3)
