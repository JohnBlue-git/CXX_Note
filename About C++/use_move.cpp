
// Do:
// std::move is a utility in C++ that indicates an object can be "moved from" rather than copied.
// This is particularly useful for optimizing performance by allowing the transfer of resources instead of duplicating them. 

// Syntax:
//  T&& t:
//      This is a forwarding reference (or universal reference) which can bind to both lvalues and rvalues.
//  std::remove_reference_t<T>&&:
//      This indicates that the function returns an rvalue reference to the type T after removing any reference qualifiers.
template <typename T>
constexpr std::remove_reference_t<T>&& move(T&& t) noexcept;

// Usage:
#include <iostream>
#include <string>
#include <vector>
#include <utility> // for std::move

class MyClass {
public:
    // Constructor
    MyClass() {
        std::cout << "MyClass Constructor\n";
    }
    // Move constructor
    // to deal with pointer / smart pointer / other complex memeber properly
    //      except smart pointers (they will be managed automatically)
    MyClass(MyClass&& other) noexcept : world(other.world) {
        std::cout << "MyClass Move Constructor\n";

        // Pointer Transfer:
        //  The pointer will be moved from the source object to the destination object.
        //  After the move, the source object's pointer will still point to the same memory location
        //  , but you need to ensure that it doesn’t lead to double deletion.
        other.world = nullptr; // Leave the moved-from object in a valid state
    }
    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        std::cout << "MyClass Move Assignment Constructor\n";

        if (this != &other) {
            delete world;      // Clean up existing resource
            world = other.world;
            other.world = nullptr;
        }
        return *this;
    }
    // Disable
    MyClass(const MyClass&) = delete;
    MyClass& operator=(const MyClass&) = delete;
    // Deconstructor
    ~MyClass() {
        std::cout << "MyClass Destructor\n";
        delete world;
    }

    void hello() {
        std::cout << "Hello";
        if (world) std::cout << *world;
        std::cout << "\n";
    }
public:
    std::string *world = new std::string(" World");
    int data = 3;
};

int main()
{
    // After moving, source may be in a valid but unspecified state
    // and should not be used without reinitialization.

    // After using std::move() on an object, the object itself may be in a "valid but unspecified" state
    // , meaning its state is undefined but it is destructible and assignable !!!

    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination = std::move(source);  // Move source to destination

    MyClass obj;
    obj.hello(); // hello world

    MyClass obj2(std::move(obj));
    obj.hello(); // hello
    obj2.hello();// hello world

    std::cout << obj.data << "\n";

    return 0;
}