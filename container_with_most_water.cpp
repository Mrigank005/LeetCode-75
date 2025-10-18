#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            // Calculate current area
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentArea = width * currentHeight;
            
            // Update max area
            maxArea = max(maxArea, currentArea);
            
            // Move the pointer at the shorter height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: height = ";
    printVector(height1);
    cout << endl;
    cout << "Output: " << solution.maxArea(height1) << endl;
    cout << "Expected: 49" << endl;
    cout << "Explanation: Lines at index 1 (height=8) and index 8 (height=7), width=7, area=7*7=49" << endl << endl;
    
    // Test case 2
    vector<int> height2 = {1, 1};
    cout << "Test 2: height = ";
    printVector(height2);
    cout << endl;
    cout << "Output: " << solution.maxArea(height2) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test case 3 - Increasing heights
    vector<int> height3 = {1, 2, 3, 4, 5};
    cout << "Test 3: height = ";
    printVector(height3);
    cout << endl;
    cout << "Output: " << solution.maxArea(height3) << endl;
    cout << "Expected: 6 (indices 0 and 4: width=4, height=1)" << endl << endl;
    
    // Test case 4 - Same heights
    vector<int> height4 = {5, 5, 5, 5};
    cout << "Test 4: height = ";
    printVector(height4);
    cout << endl;
    cout << "Output: " << solution.maxArea(height4) << endl;
    cout << "Expected: 15 (any two farthest lines: width=3, height=5)" << endl << endl;
    
    // Test case 5 - Large difference
    vector<int> height5 = {1, 100, 1};
    cout << "Test 5: height = ";
    printVector(height5);
    cout << endl;
    cout << "Output: " << solution.maxArea(height5) << endl;
    cout << "Expected: 2 (indices 0 and 2: width=2, height=1)" << endl;
    
    return 0;
}