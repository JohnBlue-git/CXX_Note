#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("data.txt");

    int value;

    // Good way to read
    while (in >> value) {
        cout << "Read: " << value << endl;
    }

    // Check stream status
    cout << "\nBefore rewind:\n";
    cout << "eof() = " << in.eof() << endl;
    cout << "fail() = " << in.fail() << endl;

    // Clear error flags
    in.clear();

    // Rewind to the beginning of the file
    in.seekg(0, ios::beg);

    cout << "\nAfter rewind, reading again:\n";
    while (in >> value) {
        cout << "Read: " << value << endl;
    }

    in.close(); // Always good to close the file
    return 0;
}
