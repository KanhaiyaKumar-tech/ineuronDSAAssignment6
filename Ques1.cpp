#include <vector>
#include<iostream>
#include <string>
using namespace std;

vector<int> findPermutation(std::string s) {
    int n = s.length();
    vector<int> perm(n + 1);

    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            perm[i] = low++;
        } else {
            perm[i] = high--;
        }
    }

    perm[n] = low;
    for (int i = 0; i < n + 1; i++) {
        perm[i] -= high;
    }

    return perm;
}

int main() {
    string s = "IDID";
    vector<int> permutation = findPermutation(s);

    for (int num : permutation) {
        cout << num << " ";
    }

    return 0;
}

