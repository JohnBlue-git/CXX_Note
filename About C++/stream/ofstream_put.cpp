#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("output.txt");

    out << "Hello, world!" << endl;  // write a full string

    out.put('A');  // write a single character
    out.put('\n');
    out.put('B');

    out.close();
    return 0;
}