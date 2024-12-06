#include <iostream>
#include <map>
int main() {
    std::map<int, int> numbers1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    std::map<int, int> numbers2 = {{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}, {6, 60}, {7, 70}, {8, 80}, {9, 90}};
    
    std::map<int, int>::iterator it1;
    std::map<int, int>::iterator it2;
    
    it1 = numbers1.begin();
    it2 = numbers2.begin();
    
    while (it1 != numbers1.end() || it2 != numbers2.end()) {
        if (it1 != numbers1.end()) {
            std::cout << it1->first << ": " << it1->second;
            ++it1;
            if (it2 != numbers2.end()) {
                std::cout << ", " << it2->second;
                ++it2;
            }
        }
        else if (it2 != numbers2.end()) {
            std::cout << it2->first << ": " << it2->second;
            ++it2;
        }

        if (it1 != numbers1.end() || it2 != numbers2.end()) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
