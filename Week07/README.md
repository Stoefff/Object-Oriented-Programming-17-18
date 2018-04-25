### Seminar - 04.04.18

## Exceptions
Used to handle exceptional events which happened in the code  
Use the keyword `throw` to push an error, returns like a `return;`  
**Slow, but convenient**  

### How does it work
When exception is thrown the program stop further progress and goes reverse in
stack(in functions in functions and lines of code) and looks for try/catch block
to handle the exception. If there such one present, the programs stops from the
main

### Try/catch blocks
**Many catch blocks are possible for handling different exceptions**  
Always catch exceptions with `&`
```c++
// Throw is written in the constructor block
if(age < 0){
    throw std::invalid_argument(Age age);
}

try{
    //Code in which to catch exception
    Student s(age);
} catch(exception& e){
    //Handle exception
}
```

### Try/catch in dynamic allocation
```c++
try{
    char* str = new char[100]
} catch(std::bad_alloc& e){
    cerr << e.what();
}
```

### Upside of exceptions
* Very convenient for the coder
* Make more sense
* Easy to comprehend

### Downside of exceptions
* Makes the program slow af - because of stack movement
* When an object throw exception, all other dependent objects should also be
destroyed, meaning destructors are called, which is also very slow for the code

### Throwing in catch block is allowed
Used when we should re-throw the exception for an above in the stack try/catch
block. This is possible with just the help of the keyword `throw;`

### New things in c++ v.>11
Good way of writing exceptions for functions and their declarations
```c++
void f() throw(int){
    //Implementation
}
```

### `R` and `L` value
* `R` value - right side of `=` and this is the one that accepts change when `=`
* `L` value - left side of `=` and this is the one that is copied from when `=`

**An exception could throw an exception :laughing:**
