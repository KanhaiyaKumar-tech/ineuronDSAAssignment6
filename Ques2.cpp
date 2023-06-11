#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / n;
        int col = mid % n;
        int midElement = matrix[row][col];

        if (midElement == target) {
            return true;
        } else if (midElement < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> matrix;

    std::cout << "Enter the elements of the matrix row by row (enter -1 to stop):" << std::endl;
    int value;
    while (true) {
        std::vector<int> row;
        while (std::cin >> value && value != -1) {
            row.push_back(value);
        }
        if (row.empty()) {
            break;
        }
        matrix.push_back(row);
    }

    int target;
    std::cout << "Enter the target value: ";
    std::cin >> target;

    bool found = searchMatrix(matrix, target);

    std::cout << "Output: " << (found ? "true" : "false") << std::endl;

    return 0;
}
