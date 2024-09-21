#include <iostream>
#include <vector>
#include <algorithm>

//
// Lambda in class
//

class MyClass {
private:
    int var = 3;

public:
    static void staticFunc() {}

    void memberFunc() const {}

    void lambdaFunc() const {
        auto func = [this]() {
            // use static memeber, don't need this ptr
            MyClass::staticFunc();

            // use memeber, need [this]
            var; // var = 6 invalid
            memberFunc();
        };
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
