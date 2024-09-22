/*
There are three kinds of smart pointers available in C++:

1. std::unique_ptr:
    * std::unique_ptr manages a single Object and ensures that when the pointer is destroyed (e.g., when it goes out of scope), the associated memory is automatically released.
    * It cannot be copied but can be moved.
    * It is the lightest-weight smart pointer.
    * It is typically used when a single ownership of a resource is needed.

2. std::shared_ptr:
    * std::shared_ptr allows multiple pointers to manage the same Object.
    * It maintains a reference count internally and automatically deallocates the Object when the last shared_ptr pointing to it is destroyed.
    * It is thread-safe for reading and writing when used with proper synchronization.
    * It is heavier than std::unique_ptr due to the overhead of reference counting.
    * It is used when multiple ownership or shared ownership of a resource is required.

3. std::weak_ptr:
    * std::weak_ptr is used in conjunction with std::shared_ptr to break circular references.
    * It provides a non-owning "weak" reference to an Object managed by std::shared_ptr without affecting its reference count.
    * It is useful for preventing strong reference cycles that can lead to memory leaks.
    * It can be converted to std::shared_ptr to access the Object if it still exists.
*/

#include <iostream>
#include <memory> // for smart pointers

class Object : public std::enable_shared_from_this<Object> {
public:
    Object() {
        std::cout << "Object Constructor\n";
    }
    Object(int num) {
        std::cout << "Object Constructor\n";
    }
    Object(Object&& other) {
        std::cout << "Object Move Constructor\n";
    }
    ~Object() {
        std::cout << "Object Destructor\n";
    }

    void hello() {
        std::cout << "Hello\n";

        // About share from this VS raw this pointer
        // Ownership Management:
        //     Raw Pointer: Does not manage the object's lifetime. You must manually ensure that the object is deleted when it's no longer needed, which can lead to memory leaks or dangling pointers.
        //     std::shared_ptr: Automatically manages the object's lifetime using reference counting. When the last shared_ptr to the object is destroyed, the object is deleted.
        // Safety:
        //     Raw Pointer: If you try to use a raw pointer after the object it points to has been deleted, you'll encounter undefined behavior.
        //     std::shared_ptr with enable_shared_from_this: Provides a safe way to access the object via shared_from_this(), ensuring that the pointer is valid and that the object remains alive as long as there are shared_ptrs pointing to it.
        // Shared Ownership:
        //     Raw Pointer: Does not allow for shared ownership; if multiple parts of your code need to share ownership, you'll end up with potential issues.
        //     std::shared_ptr: Supports shared ownership, making it easy to pass ownership around without worrying about who is responsible for deleting the object.
        //
        // Important Notes:
        //    You must ensure that the object is managed by a std::shared_ptr before calling shared_from_this(). If you call it on an object that is not owned by a shared_ptr, it will result in undefined behavior.
        //    It helps in avoiding common pitfalls of raw pointers and ensures proper reference counting.
        //
        // Usage:
        //std::shared_ptr<Object> self = shared_from_this();
        //auto self(shared_from_this());
        // ... use self pointer ...
    }
};

int main() {
    //
    // Unique pointer
    //

    /// Creating a unique_ptr
    // way 1
    Object* uniObj = new Object(); // use Object uniObj; will cause invalid pointer
    std::unique_ptr<Object> uniPtr(uniObj);
    uniObj->hello(); // still can use
    // way 2
    //std::unique_ptr<Object> uniPtr = std::make_unique<Object>();
    //std::unique_ptr<Object> uniPtr = std::make_unique<Object>(3);
    
    // Transferring ownership to another unique_ptr using std::move
    std::unique_ptr<Object> uniPtr2 = std::move(uniPtr);
    if (!uniPtr) {
        std::cout << "uniPtr is null after move." << std::endl;
    }

    //
    // Share pointer & Weak pointer
    //

    // Creating a shared pointer with resource ownership
    // way 1
    Object* shrObj = new Object();
    std::shared_ptr<Object> shrPtr(shrObj);
    // way 2
    //std::shared_ptr<Object> shrPtr = std::make_shared<Object>();
    //std::shared_ptr<Object> shrPtr = std::make_shared<Object>(3);

    // Sharing
    std::shared_ptr<Object> shrPtr2 = shrPtr;
    shrPtr->hello();
    shrPtr2->hello();

    // Creating a weak pointer to the previously created shared object
    std::weak_ptr<Object> wkPtr = shrPtr;

    // Accessing the object using weak_ptr
    if (auto lockedObj = wkPtr.lock()) { // lock() returns a shared_ptr
        lockedObj->hello();
    } else {
        std::cout << "The object has been destroyed." << std::endl;
    }

    // Resetting the shared pointer, which will destroy the object
    shrPtr.reset();
    shrPtr2.reset();
    //shrObj.hello(); still exists

    // Checking the weak pointer again
    if (auto lockedObj = wkPtr.lock()) {
        lockedObj->hello();
    } else {
        std::cout << "The object has been destroyed." << std::endl;
    }

    return 0;
}
