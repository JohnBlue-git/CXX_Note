#include <iostream>
#include <memory>
#include <functional>

class MyClass : public std::enable_shared_from_this<MyClass> {
public:
    void setupCallback1(std::function<void()> &callbackStorage) {
        // Get a shared_ptr from 'this'
        std::shared_ptr<MyClass> self = shared_from_this();
        std::weak_ptr<MyClass> weakSelf = self;

        // Store the lambda that captures the weak pointer
        callbackStorage = [weakSelf]() {
            if (auto shared = weakSelf.lock()) {
                std::cout << "Object is still alive, safe to use: " << shared.get() << std::endl;
                shared->doSomething();
            } else {
                std::cout << "Object has been destroyed. Not calling method." << std::endl;
            }
        };
    }

    void setupCallback2(std::function<void()> &callbackStorage) {
        // Get a shared_ptr from 'this'
        std::weak_ptr<MyClass> weakSelf = shared_from_this();

        // Store the lambda that captures the weak pointer
        callbackStorage = [weakSelf]() {
            auto self = weakSelf.lock();
            if (!self) {
                std::cout << "Object has been destroyed. Not calling method." << std::endl;
                return;
            }
            std::cout << "Object is still alive, safe to use: " << self.get() << std::endl;
            self->doSomething();
        };
    }

    void doSomething() {
        std::cout << "Doing something!" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor called" << std::endl;
    }
};

int main() {
    std::function<void()> storedCallback1;
    std::function<void()> storedCallback2;

    {
        std::shared_ptr<MyClass> obj = std::make_shared<MyClass>();

        // Store memeber functions as callabck
        // , which could be use later
        //   or queue in eventloop
        obj->setupCallback1(storedCallback1);
        obj->setupCallback2(storedCallback2);
    } // obj goes out of scope and is destroyed here

    // Simulate delayed execution
    std::cout << "Calling stored callback after object is destroyed:\n";
    storedCallback1(); // Should not call doSomething, should say "Object has been destroyed"
    storedCallback2(); // Should not call doSomething, should say "Object has been destroyed"

    return 0;
}
