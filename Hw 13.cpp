#include <iostream>
#include <map>
int main() {
    std::map<int, int> numbers1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                                   {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    std::map<int, int> numbers2 = {{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50},
                                   {6, 60}, {7, 70}, {8, 80}, {9, 90}};
    auto it1 = numbers1.begin();
    auto it2 = numbers2.begin();
    while (it1 != numbers1.end() && it2 != numbers2.end()) {
        it1->second = it1->second; 
        it1++; 
        it2->second = it2->second; 
        numbers1[it2->first] = it2->second; 
        it2++; 
    }
    std::cout << "Interlaced map (numbers1): ";
    for (const auto& pair : numbers1) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;
    return 0;
}
