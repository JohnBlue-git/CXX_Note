/*

typedef std::function<int(int)> Callback;

and

using Callback = std::function<int(int)>;

are the same ...

Advantage with "using":

    Readability:
    Many developers find using to be more readable and intuitive, especially for complex type definitions.

    Template Aliases:
    using can be used to create template aliases, which typedef cannot do. For example:
    template <typename T>
    using Vec = std::vector<T>;

    Consistency:
    using aligns with other modern C++ features and syntax, making it a preferred choice in contemporary C++ codebases.
*/


#include <iostream>
#include <functional>

using Callback = std::function<int(int)>;

void processNumbers(Callback callback) {
    std::cout << "Result: " << callback(9) << std::endl;
}

int main()
{
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
    
    // Pass callback
    processNumbers(lambdaFunc);

    return 0;
}