#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        
        return -1;
    }
};

// Alternative approach using Prefix Sum
class SolutionAlternative {
public:
    int pivotIndex(vector<int>& nums) {
        // Calculate total sum of array
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        
        // Loop through each index
        for (int i = 0; i < nums.size(); i++) {
            // Right sum = total sum - left sum - current element
            int rightSum = totalSum - leftSum - nums[i];
            
            // Check if pivot found
            if (leftSum == rightSum) {
                return i;
            }
            
            // Add current element to left sum for next iteration
            leftSum += nums[i];
        }
        
        // No pivot found
        return -1;
    }
};

void printVector(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]";
}

void explainPivot(const vector<int>& nums, int pivot) {
    if (pivot == -1) {
        cout << "No pivot index found" << endl;
        return;
    }
    
    int leftSum = 0;
    for (int i = 0; i < pivot; i++) {
        leftSum += nums[i];
    }
    
    int rightSum = 0;
    for (int i = pivot + 1; i < nums.size(); i++) {
        rightSum += nums[i];
    }
    
    cout << "Pivot index: " << pivot << endl;
    cout << "Left sum: " << leftSum << ", Right sum: " << rightSum << endl;
}

int main() {
    Solution solution;
    SolutionAlternative solutionAlt;
    
    // Test case 1
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    cout << "Test 1: nums = ";
    printVector(nums1);
    cout << endl;
    int result1 = solution.pivotIndex(nums1);
    cout << "Result: " << result1 << endl;
    cout << "Alternative: " << solutionAlt.pivotIndex(nums1) << endl;
    explainPivot(nums1, result1);
    cout << "Expected: 3" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    cout << "Test 2: nums = ";
    printVector(nums2);
    cout << endl;
    int result2 = solution.pivotIndex(nums2);
    cout << "Result: " << result2 << endl;
    cout << "Alternative: " << solutionAlt.pivotIndex(nums2) << endl;
    explainPivot(nums2, result2);
    cout << "Expected: -1" << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {2, 1, -1};
    cout << "Test 3: nums = ";
    printVector(nums3);
    cout << endl;
    int result3 = solution.pivotIndex(nums3);
    cout << "Result: " << result3 << endl;
    cout << "Alternative: " << solutionAlt.pivotIndex(nums3) << endl;
    explainPivot(nums3, result3);
    cout << "Expected: 0" << endl << endl;
    
    // Test case 4 - Single element
    vector<int> nums4 = {5};
    cout << "Test 4: nums = ";
    printVector(nums4);
    cout << endl;
    int result4 = solution.pivotIndex(nums4);
    cout << "Result: " << result4 << endl;
    cout << "Alternative: " << solutionAlt.pivotIndex(nums4) << endl;
    explainPivot(nums4, result4);
    cout << "Expected: 0" << endl << endl;
    
    // Test case 5 - All zeros
    vector<int> nums5 = {0, 0, 0, 0};
    cout << "Test 5: nums = ";
    printVector(nums5);
    cout << endl;
    int result5 = solution.pivotIndex(nums5);
    cout << "Result: " << result5 << endl;
    cout << "Alternative: " << solutionAlt.pivotIndex(nums5) << endl;
    explainPivot(nums5, result5);
    cout << "Expected: 0" << endl << endl;
    
    // Test case 6 - Negative numbers
    vector<int> nums6 = {-1, -1, -1, 0, 1, 1};
    cout << "Test 6: nums = ";
    printVector(nums6);
    cout << endl;
    int result6 = solution.pivotIndex(nums6);
    cout << "Result: " << result6 << endl;
    cout << "Alternative: " << solutionAlt.pivotIndex(nums6) << endl;
    explainPivot(nums6, result6);
    cout << "Expected: 0" << endl << endl;
    
    // Test case 7 - Pivot at end
    vector<int> nums7 = {1, 2, 3, 4, 5, 15};
    cout << "Test 7: nums = ";
    printVector(nums7);
    cout << endl;
    int result7 = solution.pivotIndex(nums7);
    cout << "Result: " << result7 << endl;
    cout << "Alternative: " << solutionAlt.pivotIndex(nums7) << endl;
    explainPivot(nums7, result7);
    cout << "Expected: 5" << endl;
    
    return 0;
}