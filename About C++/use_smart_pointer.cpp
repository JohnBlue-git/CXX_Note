/*
There are three kinds of smart pointers available in C++:
1. std::unique_ptr:
    * std::unique_ptr manages a single object and ensures that when the pointer is destroyed (e.g., when it goes out of scope), the associated memory is automatically released.
    * It cannot be copied but can be moved.
    * It is the lightest-weight smart pointer.
    * It is typically used when a single ownership of a resource is needed.
2. std::shared_ptr:
    * std::shared_ptr allows multiple pointers to manage the same object.
    * It maintains a reference count internally and automatically deallocates the object when the last shared_ptr pointing to it is destroyed.
    * It is thread-safe for reading and writing when used with proper synchronization.
    * It is heavier than std::unique_ptr due to the overhead of reference counting.
    * It is used when multiple ownership or shared ownership of a resource is required.
3. std::weak_ptr:
    * std::weak_ptr is used in conjunction with std::shared_ptr to break circular references.
    * It provides a non-owning "weak" reference to an object managed by std::shared_ptr without affecting its reference count.
    * It is useful for preventing strong reference cycles that can lead to memory leaks.
    * It can be converted to std::shared_ptr to access the object if it still exists.
*/

#include <iostream>
#include <memory> // for smart pointers

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor\n";
    }

    ~MyClass() {
        std::cout << "MyClass Destructor\n";
    }

    void hello() {
        std::cout << "Hello from MyClass!\n";
    }
};

int main() {
    // std::unique_ptr example
    std::unique_ptr<MyClass> uniquePtr(new MyClass());
    uniquePtr->hello();
   //     cannot be copied
   //std::unique_ptr<int> ptr2 = ptr1;
   //     can be moved
    std::unique_ptr<int> movePtr = std::move(uniquePtr);  
    // Now uniquePtr is nullptr because ownership is transferred to movePtr
    if (uniquePtr == nullptr) {
        std::cout << "uniquePtr is nullptr\n";
    }
   
    // std::shared_ptr example
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
    sharedPtr1->hello();
    sharedPtr2->hello();

    // std::weak_ptr example
    std::weak_ptr<MyClass> weakPtr = sharedPtr1;
    std::shared_ptr<MyClass> sharedPtr3 = weakPtr.lock(); // Convert weak_ptr to shared_ptr
    if (sharedPtr3) {
        sharedPtr3->hello();
    } else {
        std::cout << "The object has been destroyed.\n";
    }

    // Note: Memory is automatically managed by smart pointers
    // No need to manually delete objects allocated with new.

    return 0;
}
