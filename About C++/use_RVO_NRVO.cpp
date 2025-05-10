/*
0. Both RVO and NRVO are allowed (but not required) by the C++ standard.
In C++17, RVO is mandatory in certain cases (like direct return of a temporary object).
Most modern compilers (GCC, Clang, MSVC) apply these optimizations aggressively in release mode.

1. Compiler-Dependent Behavior
- Most modern compilers **support RVO and NRVO**, but:
  - **RVO (unnamed return)** is **mandatory** in C++17 and newer — compilers **must** eliminate the copy/move.
  - **NRVO (named return)** is **optional**, even in C++20 or later — compilers may or may not optimize it.
| Compiler | RVO | NRVO |
|----------|-----|------|
| GCC      | ✔️  | ✔️ (most cases) |
| Clang    | ✔️  | ✔️ |
| MSVC     | ✔️  | ✔️ (somewhat less aggressive than GCC/Clang) |

2. Enabling Optimizations (How-To)
You typically need to enable **compiler optimizations** (especially for NRVO) using flags:

✅ GCC / Clang
Compile with:
```bash
g++ -std=c++17 -O2 main.cpp -o main
```
- `-O2` or `-O3`: Enables optimizations (including NRVO).
- `-std=c++17`: Ensures mandatory RVO applies.

✅ MSVC (Visual Studio or CLI)
- Use `/O2` flag for full optimization:
```cmd
cl /O2 /std:c++17 main.cpp
```

3. Confirming Optimization Worked
You can **verify if RVO/NRVO is applied** by:

✅ Watching output:
If you don’t see `Copy Constructor` or `Move Constructor` called — optimization likely applied.

✅ Use `-fno-elide-constructors` (GCC/Clang)
To **disable RVO/NRVO** for testing:
```bash
g++ -std=c++17 -O0 -fno-elide-constructors main.cpp
```
*/
#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "Constructor\n"; }
    MyClass(const MyClass&) { std::cout << "Copy Constructor\n"; }
    MyClass(MyClass&&) { std::cout << "Move Constructor\n"; }
    ~MyClass() { std::cout << "Destructor\n"; }
};

// RVO Example (Unnamed Return Value)
MyClass createObjectRVO() {
    return MyClass();  // RVO can eliminate move/copy here
}

// NRVO Example (Named Return Value)
MyClass createObjectNRVO() {
    MyClass obj;        // Named object
    return obj;         // NRVO may eliminate copy/move here
}

int main() {
    MyClass objRVO = createObject();  // No copy/move with RVO
// Constructor
// Destructor

    MyClass obj = createObject();  // No copy/move with NRVO
// Constructor
// Destructor
}
