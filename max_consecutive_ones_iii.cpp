#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLength = 0;
        
        // Expand window with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If we encounter a 0, increment zero count
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            // If zero count exceeds k, shrink window from left
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            // Update maximum length (current window size)
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

// Alternative approach: More explicit tracking
class SolutionAlternative {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int zeroCount = 0;
        int maxLength = 0;
        
        while (right < nums.size()) {
            // Expand window: add element at right
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            // Shrink window while condition violated
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            // Update result with current valid window size
            maxLength = max(maxLength, right - left + 1);
            
            // Move right pointer
            right++;
        }
        
        return maxLength;
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

int main() {
    Solution solution;
    SolutionAlternative solutionAlt;
    
    // Test case 1
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    int k1 = 2;
    cout << "Test 1: nums = ";
    printVector(nums1);
    cout << ", k = " << k1 << endl;
    cout << "Result: " << solution.longestOnes(nums1, k1) << endl;
    cout << "Alternative: " << solutionAlt.longestOnes(nums1, k1) << endl;
    cout << "Expected: 6" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k2 = 3;
    cout << "Test 2: nums = ";
    printVector(nums2);
    cout << ", k = " << k2 << endl;
    cout << "Result: " << solution.longestOnes(nums2, k2) << endl;
    cout << "Alternative: " << solutionAlt.longestOnes(nums2, k2) << endl;
    cout << "Expected: 10" << endl << endl;
    
    // Test case 3 - All ones
    vector<int> nums3 = {1,1,1,1,1};
    int k3 = 0;
    cout << "Test 3: nums = ";
    printVector(nums3);
    cout << ", k = " << k3 << endl;
    cout << "Result: " << solution.longestOnes(nums3, k3) << endl;
    cout << "Alternative: " << solutionAlt.longestOnes(nums3, k3) << endl;
    cout << "Expected: 5" << endl << endl;
    
    // Test case 4 - All zeros
    vector<int> nums4 = {0,0,0,0};
    int k4 = 2;
    cout << "Test 4: nums = ";
    printVector(nums4);
    cout << ", k = " << k4 << endl;
    cout << "Result: " << solution.longestOnes(nums4, k4) << endl;
    cout << "Alternative: " << solutionAlt.longestOnes(nums4, k4) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 5 - k = 0 with mixed values
    vector<int> nums5 = {1,1,0,1,1,1};
    int k5 = 0;
    cout << "Test 5: nums = ";
    printVector(nums5);
    cout << ", k = " << k5 << endl;
    cout << "Result: " << solution.longestOnes(nums5, k5) << endl;
    cout << "Alternative: " << solutionAlt.longestOnes(nums5, k5) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test case 6 - Single element
    vector<int> nums6 = {0};
    int k6 = 1;
    cout << "Test 6: nums = ";
    printVector(nums6);
    cout << ", k = " << k6 << endl;
    cout << "Result: " << solution.longestOnes(nums6, k6) << endl;
    cout << "Alternative: " << solutionAlt.longestOnes(nums6, k6) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}