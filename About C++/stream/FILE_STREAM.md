## 📘 File Streams in C++

C++ provides file I/O through the **file stream classes** in `<fstream>`:

| Class      | Purpose       | Used for           |
| ---------- | ------------- | ------------------ |
| `ifstream` | Input stream  | Reading from files |
| `ofstream` | Output stream | Writing to files   |
| `fstream`  | Input/output  | Both read & write  |

Each behaves like `cin`/`cout`, but uses files as the source or destination.

---

## Explain good() fail() bad() eof()
* `in >> value` reads integers from the file.
* The stream condition flags are checked after each read:
  * `good()` → returns `true` if everything is OK.
  * `fail()` → `true` if a logical error occurred (e.g., wrong input type).
  * `bad()` → `true` if a read/write error occurred (e.g., hardware issue).
  * `eof()` → `true` if the **end of file** has been reached.
```cpp
/*
data.txt

1 2
3 4
5 6

*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in;
    in.open("data.txt");
    if(in.fail()){
        cout << "file opening is failed...";
        exit(1);
    }
    char value;
    while (!in.eof())
    {
        in >> value;
        cout << value << endl;
        cout << "good()=" << in.good() << ",";
        cout << "fail()=" << in.fail() << ",";
        cout << "bad()=" << in.bad() << ",";
        cout << "eof()=" << in.eof() <<endl;
        /*
        1
        good()=1,fail()=0,bad()=0,eof()=0
        ...
        5
        good()=1,fail()=0,bad()=0,eof()=0
        6
        good()=1,fail()=0,bad()=0,eof()=0
        6
        good()=0,fail()=1,bad()=0,eof()=1
        */
    }
    return 0;
}
```
In last round, eof() was not false and enter the loop.
\
However, in >> value; can only reach '\n', which is not in format 'char', so it will print the last value. 

### ⚠️ Better usage : `while (!in.eof())`
This can cause one extra (invalid) read after EOF. Better approach:
```cpp
while (in >> value) {
    // read successfully
}
```
