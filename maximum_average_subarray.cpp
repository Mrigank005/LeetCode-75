#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Calculate sum of first window
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        int maxSum = windowSum;
        
        // Slide the window: remove leftmost element, add rightmost element
        for (int i = k; i < nums.size(); i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, windowSum);
        }
        
        // Return maximum average
        return (double)maxSum / k;
    }
};

void printVector(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution solution;    
    // Test case 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Test 1: nums = ";
    printVector(nums1);
    cout << ", k = " << k1 << endl;
    cout << "Result: " << solution.findMaxAverage(nums1, k1) << endl;
    cout << "Expected: 12.75000" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {5};
    int k2 = 1;
    cout << "Test 2: nums = ";
    printVector(nums2);
    cout << ", k = " << k2 << endl;
    cout << "Result: " << solution.findMaxAverage(nums2, k2) << endl;
    cout << "Expected: 5.00000" << endl << endl;
    
    // Test case 3 - All negative numbers
    vector<int> nums3 = {-1, -2, -3, -4, -5};
    int k3 = 3;
    cout << "Test 3: nums = ";
    printVector(nums3);
    cout << ", k = " << k3 << endl;
    cout << "Result: " << solution.findMaxAverage(nums3, k3) << endl;
    cout << "Expected: -2.00000" << endl << endl;
    
    // Test case 4 - Large array with k = n
    vector<int> nums4 = {0, 1, 1, 3, 3};
    int k4 = 5;
    cout << "Test 4: nums = ";
    printVector(nums4);
    cout << ", k = " << k4 << endl;
    cout << "Result: " << solution.findMaxAverage(nums4, k4) << endl;
    cout << "Expected: 1.60000" << endl << endl;
    
    // Test case 5 - Mixed positive and negative
    vector<int> nums5 = {4, 0, 4, 3, 3};
    int k5 = 5;
    cout << "Test 5: nums = ";
    printVector(nums5);
    cout << ", k = " << k5 << endl;
    cout << "Result: " << solution.findMaxAverage(nums5, k5) << endl;
    cout << "Expected: 2.80000" << endl;
    
    return 0;
}