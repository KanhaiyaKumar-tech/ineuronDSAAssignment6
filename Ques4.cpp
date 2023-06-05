#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int findMaxLength(std::vector<int>& nums) {
    int n = nums.size();
    std::unordered_map<int, int> countMap; // Stores the count of 0s and 1s
    int maxLength = 0;
    int count = 0;

    countMap[0] = -1; // Initialize the count map with an initial count of 0

    for (int i = 0; i < n; i++) {
        // Increment count for 1 and decrement count for 0
        count += nums[i] == 1 ? 1 : -1;

        // If the count is already present in the map, update the maximum length
        if (countMap.find(count) != countMap.end()) {
            maxLength = std::max(maxLength, i - countMap[count]);
        }
        // Otherwise, store the current count in the map
        else {
            countMap[count] = i;
        }
    }

    return maxLength;
}

int main() {
    std::vector<int> nums = {0, 1};
    int maxLength = findMaxLength(nums);

    cout << maxLength << std::endl;

    return 0;
}

