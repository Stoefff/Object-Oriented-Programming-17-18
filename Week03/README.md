### Niki's seminar - 07.03.18

### Preprocessor -


### Semerdjiev(Armqnov) lecture - 08.03.18

#### Types of files:
* File types by position:
** Fixed position
*** Streams - stream from the keyboard, the network
** Not fixed position - normal files
* File by operation type:
** Only `READ` files
** Only `WRITE` files
** `READ` and `WRITE` files
* By data types
** Text files
** Binary files  

#### File identifier || File names:
* Root path(address)
* Relative path(address)

#### `WIN` vs. `UNIX`
* Windows path - `\` but could work with `/` too
* Unix path - only `/`  

#### Opening files as `.bin` vs `.txt`
* Binary - what is given to the stream is written the same way in the file
* Text - so what is given to the stream could be formatted or encoded to end file  

### Practicum - 08.03.18

ofstream, ifstream, fstream - Classes that create objects  

All files are actually binary and extension just tell us how to interpret the file   

#### `ios::app` vs `ios::ate` - these are modes not flags
* Both flags sets the pointer at the end of the opened  
* app doesnt let us go back from the end  
* ate could go back to already written information back in the file  

**open() and close() are just like new and delete: not closing a file is a mistake
as big as not deleting a allocated memory**

#### File stream flags: 0 or 1 - telling us the
* fail() - is stream broken
* bad() - is stream broken but different from fail()
* good() - is stream good
* eof() - is stream at the end of the file
* clear() - clear all the flags and stream is not broken

#### Functions for binary:
* read(char * )(&data), sizeof(data);
* write(char * )(&data), sizeof(data);
* streampos - type for storing the size when using the pointers

#### stricmp() - case insensitive comparing

### Enums:
Example for tricky usage
```c++
// Convention is to write in CAPS
enum Courses {
    INVALID = -1,
    MATH,
    INFORMATICS,
    COMPUTER_SCIENCE,
    COURCE_COUNT
};

const char* courses[]{ "MATH", "INFORMATICS", "COMPUTER_SCIENCE"};
//cout << courses[MATH]; - Ingenious
```

### Divided compilation
Done in order to have abstraction and encapsulation  
You don't care what your coworkers done with headers files, you just use it

#### Header guards:
They guard us from including the same thing multiple times
* #pragma once
* `#ifndef STUDENT_HEADER` `#define STUDENT_HEADER`

#### Header guard  - #pragma once:
* A type of header guard
* Work only in Windows
* Not good to use
