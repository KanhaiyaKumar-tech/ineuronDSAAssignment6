#include<iostream>
#include <vector>
using namespace std;



std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < k; p++) {
                result[i][j] += mat1[i][p] * mat2[p][j];
            }
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> mat1 = {{1, 0, 0}, {-1, 0, 3}};
    std::vector<std::vector<int>> mat2 = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};

    std::vector<std::vector<int>> result = multiply(mat1, mat2);

    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << std::endl;
    }

    return 0;
}

