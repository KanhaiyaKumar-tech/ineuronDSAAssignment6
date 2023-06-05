#include <vector>
#include<iostream>
using namespace std;

bool validMountainArray(std::vector<int>& arr) {
    int n = arr.size();
    int i = 0;

    // Check for increasing sequence
    while (i + 1 < n && arr[i] < arr[i + 1]) {
        i++;
    }

    // Check if peak is at the first or last element
    if (i == 0 || i == n - 1) {
        return false;
    }

    // Check for decreasing sequence
    while (i + 1 < n && arr[i] > arr[i + 1]) {
        i++;
    }

    // If i reaches the end, it is a valid mountain array
    return i == n - 1;
}

int main() {
    std::vector<int> arr = {2, 1};
    bool isValidMountain = validMountainArray(arr);

    cout << std::boolalpha << isValidMountain << std::endl;

    return 0;
}

