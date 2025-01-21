
#include <functional> // for std::reference_wrapper
#include <vector>
#include <iostream>

int main() {
    auto showCommon = [](const std::vector<int>& vec) {
        for (const auto& v : vec) {
            std::cout << " " << v;
        }
        std::cout << std::endl;
    };
    std::vector<int> vec4 = {1, 2, 3, 4, 5};
    std::cout << "Show vec4:\n";
    showCommon(vec4);

    auto showRef = [](const std::vector<std::reference_wrapper<int>>& vec) {
        for (auto v : vec) {
            v <<= 1;
            std::cout << " " << v;
        }
        std::cout << std::endl;
    };
    // Use constructor to insert a vector of values as reference type
    std::vector<std::reference_wrapper<int>> refVec(vec4.begin(), vec4.end());
    // Another way to insert a vector of values as reference type
    // refVec.insert(refVec.end(), vec4.begin(), vec4.end());
    std::cout << "Show refVec:\n";
    showRef(refVec);
    std::cout << "Show vec4 after call function:\n";
    showCommon(vec4);

    return 0;
}
