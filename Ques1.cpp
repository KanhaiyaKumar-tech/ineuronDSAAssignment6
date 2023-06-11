#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> reconstructPermutation(std::string& s) {
    int n = s.size();
    std::vector<int> perm(n + 1);

    // Initialize the permutation with sorted values
    for (int i = 0; i <= n; ++i) {
        perm[i] = i;
    }

    // Reconstruct the permutation based on the pattern of 'I' and 'D'
    int left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'I') {
            std::reverse(perm.begin() + left, perm.begin() + right + 2);
            left = i + 1;
            right = i + 1;
        } else {
            right = i + 1;
        }
    }

    return perm;
}

int main() {
    std::string s ;
    std::cin>>s;
    std::vector<int> perm = reconstructPermutation(s);

    std::cout << "Output: ";
    for (int num : perm) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
