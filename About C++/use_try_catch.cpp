/*

A sample to demonstract nested try catch

*/

#include <iostream>
#include <stdexcept>

void innerFunction() {
    // This function may throw an exception
    throw std::runtime_error("Error in innerFunction");
}

void outerFunction() {
    try {
        innerFunction(); // Call to a function that can throw
    } catch (const std::runtime_error& e) {
        std::cout << "Caught in outerFunction: " << e.what() << std::endl;
        throw; // Rethrow the exception to be caught by an outer handler
    }
}

int main() {
    try {
        outerFunction(); // Call to a function that may trigger an exception
    } catch (const std::runtime_error& e) {
        std::cout << "Caught in main: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception." << std::endl;
    }

    return 0;
}
