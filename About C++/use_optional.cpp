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
#include <functional> // std::reference_wrapper

//
// Common usage
//

std::optional<std::string> getName() {
    return "John Doe";
}

void commonUsage() {
    auto name = getName();
    if (name) { // the same as if (name.has_value())
        std::cout << "Name: " << *name << std::endl;
        std::cout << "Name: " << name.value() << std::endl; // name.value() will Throws if no value
    } else {
        std::cout << "No name provided" << std::endl;
    }

    name.reset();
    if (!name) {
        std::cout << "No name provided" << std::endl;
    }
}


//
// Passing std::optional as reference
//

void printOptionalString(std::optional<std::string>& opt) {
    if (opt) {
        std::cout << "Value: " << opt.value() << std::endl;
        opt.value() = "c++ is difficult";
    } else {
        std::cout << "No value provided." << std::endl;
    }
}

void passOptional() {
    const std::string str1 = "C++ is fun!";
    std::string str2(str1);
    std::optional<std::string> optStr2 = str2;

    // Outputs: Value: C++ is fun!
    printOptionalString(optStr2);
    // Outputs: Value: C++ is difficullt!
    std::cout << "Value: " << optStr2.value() << std::endl;
    
    // No value
    std::optional<std::string> optStr3;
    // Outputs: No value provided.
    printOptionalString(optStr3);
}

//
// Passing std::optional with reference inside
//

void processString(std::optional<std::reference_wrapper<std::string>> optStr) {
    if (optStr.has_value()) {
        std::cout << "String before processing: " << optStr->get() << std::endl;
        // Modify the string through the reference
        optStr->get() = "Processed " + optStr->get();
        std::cout << "String after processing: " << optStr->get() << std::endl;
    } else {
        std::cout << "No string provided to process." << std::endl;
    }
}

void referenceInside() {
    std::string myString = "Hello, World!";
    
    // Before function call
    std::optional<std::reference_wrapper<std::string>> optStr = std::ref(myString);

    // After function call
    processString(optStr);
    std::cout << "String after function call: " << myString << std::endl;

    // Passing std::nullopt
    processString(std::nullopt);
}


int main()
{
    std::cout << std::endl;
    commonUsage();

    std::cout << std::endl;
    passOptional();

    std::cout << std::endl;
    referenceInside();
}
