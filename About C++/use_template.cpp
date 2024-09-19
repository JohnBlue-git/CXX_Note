#include <iostream>

// Template function to find the maximum of two values
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Testing the max function with different types
    int intMax = max(3, 7);
    double doubleMax = max(4.56, 2.34);
    char charMax = max('a', 'b');

    std::cout << "Maximum of 3 and 7 is: " << intMax << std::endl;
    std::cout << "Maximum of 4.56 and 2.34 is: " << doubleMax << std::endl;
    std::cout << "Maximum of 'a' and 'b' is: " << charMax << std::endl;

    return 0;
}
