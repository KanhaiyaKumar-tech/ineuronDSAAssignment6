#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;



std::vector<int> findOriginalArray(std::vector<int>& changed) {
    int n = changed.size();

    if (n % 2 != 0) {
        return {}; // If the size is odd, it is not a valid doubled array
    }

    std::unordered_map<int, int> countMap;
    std::vector<int> original;

    for (int num : changed) {
        countMap[num]++;
    }

    for (int num : changed) {
        if (countMap[num] == 0) {
            continue; // Skip if the element has already been used
        }

        if (countMap[2 * num] == 0) {
            return {}; // If the double of the current element is not present, it is not a valid doubled array
        }

        original.push_back(num);
        countMap[num]--;
        countMap[2 * num]--;
    }

    return original;
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};

    std::vector<int> original = findOriginalArray(changed);

    for (int num : original) {
        cout << num << " ";
    }

    return 0;
}

