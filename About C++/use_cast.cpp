/*
Nice comparison
https://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast
*/

/* const_cast

const_cast is used to add or remove const or volatile qualifiers.
The most common use case is when you want to call a non-const function on an object that is originally const
*/
#include <iostream>

void printAndModify(int* ptr) {
    *ptr = 42;
    std::cout << "Modified value: " << *ptr << std::endl;
}

int main() {
    const int x = 10;

    // Remove const-ness (⚠️ dangerous if x is truly const!)
    printAndModify(const_cast<int*>(&x));
    // x still not change
    std::cout << "x after modification: " << x << std::endl;

    // Attempting to modify a truly const object — UB!
    int* ptr = const_cast<int*>(&x);
    *ptr = 100;  // ⚠️ Undefined Behavior!
}

/* static_cast

static_cast is used for cases where you basically want to reverse an implicit conversion
, with a few restrictions and additions.

static_cast performs no runtime checks.

This should be used if you know that you refer to an object of a specific type, and thus a check would be unnecessary.
*/
void func(void *data) {
  // Conversion from MyClass* -> void* is implicit
  MyClass *c = static_cast<MyClass*>(data);
  ...
}

int main() {
  MyClass c;
  start_thread(&func, &c)  // func(&c) will be called
      .join();
}

/* dynamic_cast
  
dynamic_cast is useful when you don't know what the dynamic type of the object is.

It returns a null pointer if the object referred to doesn't contain the type casted to as a base class
(when you cast to a reference, a bad_cast exception is thrown in that case).

🚫 What dynamic_cast cannot do: Cannot remove const, volatile, or other qualifiers.
*/
if (JumpStm *j = dynamic_cast<JumpStm*>(&stm)) {
  ...
} else if (ExprStm *e = dynamic_cast<ExprStm*>(&stm)) {
  ...
}

/*
You can not use dynamic_cast for downcast (casting to a derived class) if the argument type is not polymorphic.
*/
struct Base { };
struct Derived : Base { };
int main() {
  Derived d; Base *b = &d;
  dynamic_cast<Derived*>(b); // Invalid
}

/* Regular Cast

These casts are also called C-style cast.

A C-style cast is basically identical to trying out a range of sequences of C++ casts.

Needless to say, this is much more powerful as it combines all of const_cast, static_cast and reinterpret_cast
, but it's also unsafe, because it does not use dynamic_cast.
*/
int main() {
    double pi = 3.14159;
    int intPi = (int)pi;
}

