### Help about HW4

### The iterator should have operators - `++`, `--`, `*`

***When resizing, we should update the pointer of iterator***

**Bonus points if we write constant iterator**

**Because of the iterator, the polynomial class should have methods begin() and
end(), which return pointer to iterator and operator `==` for the iterator**

## Design patterns - created by the `Gang of 4`

### Factory
Creates objects of many different types. We have already implemented it in
HW3 in the post container. It accepts arguments of primitive types and creates
object by these arguments.  
It could be a method or a class.  
E.g. `PostContainer.addPost(char* type, char* content);`

### Abstract factory
Factory for interfaces - could created every needed class

### Proxy - restricting usage of class methods or validation
E.G. - We have a class `Admin` which is privately inherited by class `User`, which
does not implement the function of `Admin` - for example block, unblock...
E.G - For validation - Class `Authentication`, which contains class `Login`

### Singleton - not very good

### Adapter - Like proxy, but instead of restricting it adds functionality

### Bridge - just interface - no implementation allowed
The idea is to restring the visibility of the closed source

### Watcher pattern - Observer patter from js

### Object pool - for slowly working object
It creates defaultly initialized objects of these slow objects, and when some
of this objects are needed, the objects are re-initialized and pointers to it is
passed to the thing that needs it. There should be the least possible dependencies
with the object pool.

### Iterator

### RAII principle
It's idea - only use `new` in de-constructor and constructors. The memory of every
objects should be handled by them selfs internally

**Smart pointers are proxy of RAII**

### Armqnov lecture - 07.05.18 - **missed**
