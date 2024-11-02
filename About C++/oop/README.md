
# OOP and Proprietaries related to C++

## OOP

### Class
A group of abstract feature about the object (a group of functions, data, or components)

### Object
The entity of class

### Encapsulation:
A bundling of data with the mechanisms or methods

### Inheritance:
A feature to reuse or inherit code with similar behaviors or data

### Polymorphism
A feature to use the same interface for similar but different classes

### Interface
A description that defines what functions or data a class must have

### Overriding
A description that derived class want to redefined the same functions already defined in base class

### overloading (often misleading)
A mechanism define multiple functions with the same function name

### Multi - Inheritance ::
- It is property to inherent from differet parent classes
- c++ can do multi_inheritance but java,c# can't
- java and C# can use interface to implment multi_inheritance
- when to use ? \
It is useful when you don't want to create an instance of an object but want to execute some function on it (by using static functions, we don't have to depend on any entities) it can be used as interface in C++

## SOID principle
5 principle to make program easy to maintain and extend with OOP

### Single-responsibility
A class should have one and only one reason to change, meaning that a class should have only one job.

### Open-closed
Objects or entities should be open for extension but closed for modification.

### Liskov Substitution
Let q(x) be a property provable about objects of x of type T. Then q(y) should be provable for objects y of type S where S is a subtype of T. This means that every subclass or derived class should be substitutable for their base or parent class.

### Interface Segregation
A client should never be forced to implement an interface that it doesn’t use, or clients shouldn’t be forced to depend on methods they do not use.

### Dependency Inversion
Entities must depend on abstractions, not on concretions. It states that the high-level module must not depend on the low-level module, but they should depend on abstractions.

## OOP benefits

If designed properly:
- Better reusability + easy to maintain and extend (via inheritance and polymorphism + abstraction)

Meaning of data encapsulation:
- Wrapping of implementation, hiding them, preventing outside from accessing too easy.
- For me, it is also a way to organize class of implementation

## C++ related words

### public protected private
- **public** can be accessed by all others
- **protected** can only be accessed by itself or its own descendant
- **private** can only be accessed by itself

### friend
To define classes or functions that can utilize the memeber in this class

### inheritance
- **public inheritance**
- **protected inheritance** would make inherited memebers protected
- **private inheritance** would make inherited memebers private

### Upcast
To treat a derived type as though it were its base type. 
```c++
class Base {
public:
    virtual void func() const {
        std::cout << "base" << std::endl;
    }
};

class Derived : public Base {
public:
    void func() const override {
        std::cout << "derived" << std::endl;
    }
};

Derived derived;

// upcast - implicit type cast allowed
Base *ptb = &derived;

// if func() is properly override
ptb->func(); // will call Derived::func();

// if derived but want to call function defined in base 
ptb->Base::func();

// pass by reference
void proccessObj(const Base& rfc){
    rfc.func(); // will determine the correct type
}

proccessObj(derived); // will call Derived::func();
```

### Downcast
To treat a base type as though it were its derived type. 
```c++
// downcast - explicit type case required 
Derived *ptd =  (Derived*)&base;
```

### Pure VS non-Pure
pure virtual function:
```c++
virtual typeT funcname() = 0;
```
- interface class: only contains pure virtual functions
- abstract class: contains more than one pure virtual functions

## Virtual, Casting, and Binding

### Static binding
- Binding the definitions and implementations in **compile-time**

### Dynamic binding
- Bindling until **run-time**
- When use **virtual** and **override**, the compiler will do dynamic binding

## Reference
https://www.digitalocean.com/community/conceptual-articles/s-o-l-i-d-the-first-five-principles-of-object-oriented-design

