/*
We known
nlohmann::json has built-in support for JSON Pointer via json_pointer type and "_json_pointer" user-defined literal.

However
boost::json, as of Boost 1.85, does not include a JSON Pointer parser or equivalent syntax.

Instead, with boost::json, you must manually navigate the structure
*/

#include <boost/json.hpp>
#include <iostream>

namespace json = boost::json;

int main() {
    auto jv = json::parse(R"({
        "array": ["A", "B", "C"],
        "nested": {
            "one": 1,
            "two": 2,
            "three": [true, false]
        }
    })");

    json::object& obj = jv.as_object();

    // Access manually
    int val1 = obj["nested"].as_object()["one"].as_int64();
    bool val2 = obj["nested"].as_object()["three"].as_array()[1].as_bool();

    std::cout << "/nested/one = " << val1 << std::endl;
    std::cout << "/nested/three/1 = " << std::boolalpha << val2 << std::endl;

    return 0;
}
