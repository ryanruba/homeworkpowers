#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    size_t size1 = numbers1.size();
    size_t size2 = numbers2.size();
    numbers1.resize(size1 + size2);
    auto it1 = numbers1.begin();
    auto it2 = numbers2.begin();
    while (it1 != numbers1.end() && it2 != numbers2.end()) {
        it1 = numbers1.insert(it1 + 1, *it2);
        ++it2;
        ++it1;
    }
    std::cout << "Interlaced Vector";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
