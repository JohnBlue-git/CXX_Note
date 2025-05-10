/*
 Minimum Requirements:
  Boost 1.75.0** or later
  A C++17-compatible compiler (e.g., GCC 7+, Clang 5+, MSVC 2017+)
 Install Boost
  sudo apt install libboost-all-dev
*/

#include <boost/json.hpp>
#include <iostream>
#include <fstream>
#include <string>

namespace json = boost::json;

int main() {
    // --- Step 1: Create JSON object
    json::object obj;
    obj["name"] = "Alice";
    obj["age"] = 30;
    obj["skills"] = { "C++", "Python", "Boost" };

    // --- Step 2: Write JSON to file
    std::ofstream outFile("person.json");
    if (!outFile) {
        std::cerr << "Failed to open file for writing.\n";
        return 1;
    }

    outFile << json::serialize(obj);  // Compact format
    outFile.close();
    std::cout << "JSON written to person.json\n";

    // --- Step 3: Read JSON from file
    std::ifstream inFile("person.json");
    if (!inFile) {
        std::cerr << "Failed to open file for reading.\n";
        return 1;
    }

    std::string json_content((std::istreambuf_iterator<char>(inFile)),
                             std::istreambuf_iterator<char>());

    json::value parsed = json::parse(json_content);
    json::object parsed_obj = parsed.as_object();

    std::cout << "\nRead from file:\n";
    std::cout << "Name: " << parsed_obj["name"].as_string() << "\n";
    std::cout << "Age: " << parsed_obj["age"].as_int64() << "\n";
    std::cout << "First skill: " << parsed_obj["skills"].as_array()[0].as_string() << "\n";

    return 0;
}
