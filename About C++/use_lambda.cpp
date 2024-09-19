#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // Using a lambda function to print each element in the vector
    std::cout << "Printing elements of the vector using lambda:\n";
    std::for_each(numbers.begin(), numbers.end(), 
    [](int num) {
        std::cout << num << " ";
    });
    std::cout << "\n";

    // Using a lambda function to find the sum of all elements in the vector
    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(), 
    [&sum](int num) {
        sum += num;
    });
    std::cout << "Sum of elements in the vector: " << sum << "\n";

    // Using a lambda function to count the number of even numbers in the vector
    int evenCount = std::count_if(numbers.begin(), numbers.end(),
    [](int num) {
        return num % 2 == 0;
    });
    std::cout << "Number of even elements in the vector: " << evenCount << "\n";

    return 0;
}
