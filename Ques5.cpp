#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



int minProductSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    int n = nums1.size();

    std::sort(nums1.begin(), nums1.end()); // Sort nums1 in ascending order
    std::sort(nums2.rbegin(), nums2.rend()); // Sort nums2 in descending order

    int productSum = 0;

    for (int i = 0; i < n; i++) {
        productSum += nums1[i] * nums2[i];
    }

    return productSum;
}

int main() {
    std::vector<int> nums1 = {5, 3, 4, 2};
    std::vector<int> nums2 = {4, 2, 2, 5};

    int minProduct = minProductSum(nums1, nums2);

    cout << minProduct << std::endl;

    return 0;
}
