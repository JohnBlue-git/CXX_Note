#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("data.txt");

    if (!in.is_open()) {
        cerr << "Error: Failed to open file." << endl;
        return 1;
    }

    cout << "--- Reading characters with get() ---" << endl;
    char ch;
    while (in.get(ch)) {
        cout << ch;

        // Check stream state after each character read
        cout << "\t[good=" << in.good()
             << ", fail=" << in.fail()
             << ", bad=" << in.bad()
             << ", eof=" << in.eof() << "]" << endl;
    }

    // Reset stream
    in.clear();
    in.seekg(0, ios::beg);

    cout << "\n--- Reading lines with getline() ---" << endl;
    string line;
    while (getline(in, line)) {
        cout << "Line: " << line;

        // Check stream state after each line read
        cout << "\t[good=" << in.good()
             << ", fail=" << in.fail()
             << ", bad=" << in.bad()
             << ", eof=" << in.eof() << "]" << endl;
    }

    in.close();
    return 0;
}
