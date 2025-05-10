
## 🔹 What is an Input Stream?

In C++, an **input stream** is a source from which your program receives data. Common examples:
- `std::cin` — standard input (keyboard)
- `std::ifstream` — input from a file

All input streams in C++ are derived from the `std::istream` class.


## 🔹 What is a Buffer?

An **input buffer** is a temporary memory area that stores data before it's read by the program. This buffering:
- Reduces the number of direct I/O operations (which are slow).
- Helps process user or file input efficiently.

### Example:

```cpp
#include <iostream>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;  // reads input from buffer
    std::cout << "Hello, " << name << "!\n";
    return 0;
}
```

## 🔹 Dealing with Leftover Input

When using `std::cin`, characters like spaces, newlines (`\n`), or invalid input can remain in the input buffer. These leftovers may interfere with future input operations.
\
For example, the following example will go wrong:
```c++
int main(){
    int number = 0;
    cout << "plz input a number!" << endl;
    cin >> number; //假設輸入 3 後按 enter
    char symbol;
    cout << "plz input a symbol!" << endl;
    cin.get(symbol); // 假設輸入 A

    /* Result:

    plz input a number!
    3
    plz input a symbol!
                (其實這邊是換行符號!A沒辦法輸入)
    */
}
```

### 🔸 `std::cin.sync()`
- **Purpose:** Flushes (clears) the input buffer.
- **Behavior:** Discards all unread characters up to the next newline (`\n`).
- **Use case:** Quickly flush buffer after input.
- **⚠️ Warning:** This function is **implementation-defined**, meaning it may not work consistently across all compilers or platforms.
### Example:
```cpp
std::cin >> value;
std::cin.sync(); // attempt to discard leftover input (not guaranteed on all systems)
````

### 🔸 `std::cin.ignore()`
* **Purpose:** Skips characters in the input buffer.
* **Syntax:**

  ```cpp
  std::cin.ignore(n, delim);
  ```

  * `n`: Maximum number of characters to ignore.
  * `delim`: Stop ignoring when this delimiter character is found (e.g., `'\n'`).
* **Example:**
```cpp
#include <limits>
std::cin >> value;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip to end of line
// This ensures that any unwanted characters (like newline or garbage input) are removed before the next input operation.
```

### 🔄 Comparison Table
```
| Feature              | `std::cin.sync()`               | `std::cin.ignore()`                                     |
| -------------------- | ------------------------------- | ------------------------------------------------------- |
| Clears whole buffer? | ✅ Yes (usually)                 | ✅ Yes (with large limit and delimiter)                  |
| Portable?            | ❌ No (implementation-dependent) | ✅ Yes (standard-compliant)                              |
| Control?             | ❌ None                          | ✅ Full control (number of chars and stopping delimiter) |
| Use Case             | Flush all input (if it works)   | Precisely skip leftover input after reading a value     |

```

## 🔹 Comparison: `std::cin` vs `std::cin.getline()` vs `std::getline()`

| Feature                     | `std::cin`                        | `std::cin.getline()`                   | `std::getline()` (from `<string>`)      |
|-----------------------------|-----------------------------------|----------------------------------------|------------------------------------------|
| Reads into                 | Any type (e.g. `int`, `char[]`, `std::string`) | `char[]` (C-style string)              | `std::string`                            |
| Stops reading at           | Whitespace (space, tab, newline) | Newline (`\n`)                         | Newline (`\n`)                            |
| Includes delimiter?        | ❌ No                            | ❌ No (newline is discarded)           | ❌ No (newline is discarded)              |
| Handles whitespace in input| ❌ No                            | ✅ Yes (up to newline)                 | ✅ Yes (up to newline)                    |
| Removes newline from buffer| ❌ No                            | ✅ Yes                                 | ✅ Yes                                    |
| Leaves newline (`\n`) in buffer | ✅ Yes (must be cleared manually) | ❌ No (newline consumed)            | ❌ No (newline consumed)                  |
| Buffer overflow safe?      | ❌ No (risk with `char[]`)       | ⚠️ Safer with `char[]` + size         | ✅ Yes (automatic sizing)                 |
| Exception-safe             | ⚠️ No                            | ⚠️ No                                  | ✅ Yes                                    |
| Usage                      | Quick word/token input           | Fixed-size line input (C-style)        | Safe full-line input (preferred modern C++) |

### 🧪 Example: Using All Three

```cpp
#include <iostream>
#include <string>

int main() {
    char cstr[100];
    std::string str;
    std::string word;

    std::cout << "Enter a word: ";
    std::cin >> word;  // stops at first space
    std::cin.ignore(); // clear newline

    std::cout << "Enter a line (char array): ";
    std::cin.getline(cstr, 100); // reads full line into char array

    std::cout << "Enter another line (std::string): ";
    std::getline(std::cin, str); // reads full line into std::string

    std::cout << "\nResults:\n";
    std::cout << "Word: " << word << "\n";
    std::cout << "C-string: " << cstr << "\n";
    std::cout << "String: " << str << "\n";

    return 0;
}
````

### ✅ Summary

* Use `std::cin` for simple word/number input.
* Use `std::cin.getline()` when working with C-style arrays and full lines.
* Use `std::getline()` for safe and flexible line input with `std::string` (recommended for modern C++).
