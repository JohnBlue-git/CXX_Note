/*
Why use std::optional ?

Expressing Optional Values:
It clearly indicates that a value might be absent, making your code more readable and expressive.

Avoiding Sentinel Values:
Instead of using special sentinel values (like -1 or nullptr) to indicate the absence of a value, std::optional provides a type-safe way to handle optional values.

Improved Error Handling:
It simplifies error handling by avoiding the need for separate error codes or flags.
Better Code Documentation: It documents the intent of your code, making it clear when a function might not return a value12.
*/

#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> getName() {
    return "John Doe";
}

int main() {
    auto name = getName();
    if (name) {
        std::cout << "Name: " << *name << std::endl;
        std::cout << "Name: " << name.value() << std::endl; // name.value() will Throws if no value
    } else {
        std::cout << "No name provided" << std::endl;
    }

    name.reset();
    if (!name) {
        std::cout << "No name provided" << std::endl;
    }

    return 0;
}
