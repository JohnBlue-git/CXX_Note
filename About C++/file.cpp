#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Read file
    std::ifstream file("sample.txt");
    if (!file) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    std::cout << std::endl;

    file.close();

    // Append to file
    /*{
        std::ofstream appendFile("sample.txt", std::ios::app);
        if (!appendFile) {
            std::cerr << "Error opening file for appending" << std::endl;
            return EXIT_FAILURE;
        }
        
        const std::string lineToAppend = "This is a new line to append.\n";
        appendFile << lineToAppend;
        
        file.close();
    }*/

    // Rewind is not necessary in C++, but we can open the file again
    /*{
        std::ifstream file("sample.txt");
        if (!file) {
            std::cerr << "Unable to open file" << std::endl;
            return 1;
        }

        // Write to file (overwrite)
        std::ofstream writeFile("sample.txt");
        if (!writeFile) {
            std::cerr << "Error opening file for writing" << std::endl;
            return EXIT_FAILURE;
        }
        
        const std::string lineToWrite = "This is a new line to overwrite.\n";
        writeFile << lineToWrite;
        
        file.close();
    }*/

    // Calculate file size
    {
        std::ifstream file("sample.txt", std::ios::ate); // Open at end to get size
        if (!file) {
            std::cerr << "Unable to open file" << std::endl;
            return 1;
        }
        
        std::streamsize size = file.tellg(); // Get current position (size of the file)
        std::cout << "The size of the file is: " << size << " bytes" << std::endl;
        
        // Move to the end
        //file.seekg(0, std::ios::end);
        
        // Rewind to the beginning of the file
        file.seekg(0);
        
        file.close();
    }

    return 0;
}
