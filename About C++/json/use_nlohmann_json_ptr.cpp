/*
Introduction:
https://json.nlohmann.me/features/json_pointer/#introduction

Benefit:
**JSON Pointer** provides a standardized, concise, and flexible way to **access and manipulate deeply nested values** in a JSON structure.

## ✅ 1. **Clear and Concise Path Access**
Instead of deeply chained member access:
```cpp
json["nested"]["config"]["settings"]["enabled"]
```
```cpp
json["/nested/config/settings/enabled"_json_pointer]
```
This is easier to read and maintain, especially for dynamic paths.

## ✅ 2. **Dynamic Path Navigation**
You can build paths at runtime:
```cpp
std::string path = "/users/0/permissions/admin";
json::json_pointer ptr(path);
json[ptr] = true;
```

## ✅ 3. **Standardized Format**
Follows [RFC 6901](https://tools.ietf.org/html/rfc6901), so it works across:
* APIs
* Tools
* Libraries in other languages (e.g., Python, JavaScript)
This improves **interoperability**.

## ✅ 4. **Optional Access with Defaults**
You can safely access missing paths using `value()`:
```cpp
int port = json.value("/server/port"_json_pointer, 8080);
```
Avoids crashing on missing keys and provides fallback values.

## ✅ 5. **Flattening and Unflattening**
JSON Pointer enables `nlohmann::json` to:
* Convert nested objects to flat key-value pairs (like `"/a/b": 1`)
* Reconstruct the original structure from that
```cpp
auto flat = json.flatten();
auto original = flat.unflatten();
```

*/

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main() {
    // Parse JSON
    auto j = json::parse(R"({
        "array": ["A", "B", "C"],
        "nested": {
            "one": 1,
            "two": 2,
            "three": [true, false]
        }
    })");

    // ✅ Access with JSON pointer
    // json::json_pointer class is used to represent a JSON pointer
    // nlohmann::json has built-in support for JSON Pointer via json_pointer type and "_json_pointer" user-defined literal.

    // Entire root object
    auto val = j[""_json_pointer];  // Same as j
    cout << "Root: " << val.dump(2) << endl;

    // Access nested integer: /nested/one
    auto val1 = j["/nested/one"_json_pointer];  // 1
    cout << "/nested/one = " << val1 << endl;

    // Access bool in array: /nested/three/1 (false)
    auto val2 = j.at(json::json_pointer("/nested/three/1"));
    cout << "/nested/three/1 = " << val2 << endl;

    // Access non-existent key safely with default value
    auto val3 = j.value(json::json_pointer("/nested/four"), 0);  // default 0
    cout << "/nested/four (default 0) = " << val3 << endl;

    // create flattened value
    auto j_flat = j.flatten();
    cout << "j_flat = " << j_flat << endl;

    return 0;
}
