#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Helper function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[";
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Example 1
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Example 1:" << endl;
    cout << "Input: ";
    printMatrix(matrix1);
    solution.rotate(matrix1);
    cout << "Output: ";
    printMatrix(matrix1);
    cout << endl;
    
    // Example 2
    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    cout << "Example 2:" << endl;
    cout << "Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]" << endl;
    solution.rotate(matrix2);
    cout << "Output: ";
    printMatrix(matrix2);
    
    return 0;
}

/*
Time Complexity: O(n^2) - we visit each element twice (transpose + reverse)
Space Complexity: O(1) - in-place rotation, no extra space used

Approach:
1. Transpose: Convert rows to columns (swap matrix[i][j] with matrix[j][i])
2. Reverse: Reverse each row to complete the 90° clockwise rotation
*/
