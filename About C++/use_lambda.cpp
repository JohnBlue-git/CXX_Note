#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <memory> // for smart pointers

//
// Lambda in class
//

class MyClass : public std::enable_shared_from_this<MyClass> {
private:
    int var = 3;

public:
    static void staticFunc() {}

    void memberFunc() const {}

    void lambdaFunc() const {
        // via shared_from_this()
        auto self(shared_from_this());
        auto func = [self]() {
            // using static memeber don't need this ptr
            MyClass::staticFunc();

            // use memeber, need [this]
            self->var; // var = 6 invalid
            self->memberFunc();
        };

        // via this pointer
        //auto func = [this]() {
        //  ... use this pointer ...
        //};
    }

    void createTask() {
        // Create a lambda that captures `this` using shared_from_this
        auto task = [self = shared_from_this()]() {
            // Use `self`, which is a shared_ptr
        };

        // Simulate asynchronous execution
        std::thread t(task);
        t.join();
    }
};

int main() {

    //
    // Lambda
    //

    int var1 = 3;
    const int &const_var1 = var1;
    int var2 = 6;
    const int *const_var2 = &var2;

    // Define lambda
    auto lambdaFunc = [&const_var1, const_var2] (int num) {
        // *const_var1 = 3; invalid
        // const_var2 = 3; invalid
        return const_var1 + *const_var2 + num;
    };
    std::cout << "Result: " << lambdaFunc(9) << std::endl;

    // Capture all variables in the surrounding scope by value.
    int x1 = 10, y1 = 20;
    auto lambda1 = [=]() {
        std::cout << x1 << ", " << y1 << std::endl;
    };

    // Capture all variables in the surrounding scope by reference.
    int x2 = 10, y2 = 20;
    auto lambda2 = [&]() {
        x2 += 5;
        y2 += 10;
        std::cout << x << ", " << y << std::endl;
    };

    // Some varable are captured as const but some are not
    int x3 = 10;
    int y3 = 20;
    auto lambda3 = [x3, &y3]() {
        std::cout << "Captured by value (const): " << x3 << std::endl;
        y3 += 5; // Captured by reference, so this can be modified
        std::cout << "Captured by reference (mutable): " << y3 << std::endl;
    };

    //
    // Inherit callback in lambda function
    //

    // callbackFunction
    auto callbackFunction = []() {
        std::cout << "Callback function called!" << std::endl;
    };

    // callback
    std::function<void()> callback = callbackFunction;

    // Lambda capturing callback by value (copy)
    auto lambdaCapturedByCopy = [callback]() {
        std::cout << "Lambda called!" << std::endl;
        callback(); // Calling the copied callback
    };
    lambdaCapturedByCopy();

    // Lambda capturing callback by move
    auto lambdaCapturedByMove = [callback = std::move(callback)]() {
        std::cout << "Lambda called!" << std::endl;
        callback(); // Calling the moved callback
    };
    lambdaCapturedByMove();
    // After moving, callback should no longer be used in main
    // std::cout << callback ? "Callback still valid" : "Callback moved" << std::endl;

    // callback1
    std::function<void()> callback1 = callbackFunction;

    // Nested lambda function
    auto ByCopy = [callback1]() {
        auto ByMove = [callback1 = std::move(callback1)]() {
            std::cout << "Lambda called!" << std::endl;
            callback1();
        };
        ByMove();
    };
    ByCopy();
    
    //
    // With std::for_each
    //

    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // Using a lambda function to print each element in the vector
    std::cout << "Printing elements of the vector using lambda:\n";
    std::for_each(
        numbers.begin(), numbers.end(), 
        [](int num) {
            std::cout << num << " ";
        });
    std::cout << "\n";

    // Using a lambda function to find the sum of all elements in the vector
    int sum = 0;
    std::for_each(
        numbers.begin(), numbers.end(), 
        [&sum](int num) {
            sum += num;
        });
    std::cout << "Sum of elements in the vector: " << sum << "\n";

    // Using a lambda function to count the number of even numbers in the vector
    int evenCount = std::count_if(
        numbers.begin(), numbers.end(),
        [](int num) {
            return num % 2 == 0;
        });
    std::cout << "Number of even elements in the vector: " << evenCount << "\n";
    
    return 0;
}
