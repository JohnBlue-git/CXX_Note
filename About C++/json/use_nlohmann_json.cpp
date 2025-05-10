#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

int main() {
    // ✅ Create JSON object
    json person;
    person["name"] = "Alice";
    person["age"] = 30;
    person["skills"] = {"C++", "Python", "Rust"};

    // ✅ Serialize to string and print
    cout << "Serialized JSON:\n" << person.dump(4) << endl;

    // ✅ Write to file
    ofstream outFile("person.json");
    outFile << person.dump(4);  // pretty print with 4 spaces
    outFile.close();

    // ✅ Read from file
    ifstream inFile("person.json");
    json loaded;
    inFile >> loaded;

    cout << "\nLoaded from file:\n";
    cout << "Name: " << loaded["name"] << endl;
    cout << "Age: " << loaded["age"] << endl;
    cout << "First skill: " << loaded["skills"][0] << endl;

    return 0;
}
