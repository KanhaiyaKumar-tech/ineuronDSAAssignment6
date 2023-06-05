#include<iostream>
#include <vector>
using namespace std;



std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    int num = 1;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Traverse right
        for (int i = colStart; i <= colEnd; i++) {
            matrix[rowStart][i] = num++;
        }
        rowStart++;

        // Traverse down
        for (int i = rowStart; i <= rowEnd; i++) {
            matrix[i][colEnd] = num++;
        }
        colEnd--;

        // Traverse left
        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                matrix[rowEnd][i] = num++;
            }
            rowEnd--;
        }

        // Traverse up
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                matrix[i][colStart] = num++;
            }
            colStart++;
        }
    }

    return matrix;
}

int main() {
    int n = 3;

    std::vector<std::vector<int>> matrix = generateMatrix(n);

    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

