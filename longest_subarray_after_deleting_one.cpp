#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeroCount = 0;
        int maxLength = 0;
        
        // Expand window with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If we encounter a 0, increment zero count
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            // If zero count exceeds 1, shrink window from left
            // (We can delete at most 1 zero)
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            // Update maximum length (current window size)
            maxLength = max(maxLength, right - left + 1);
        }
        
        // We must delete exactly one element, so subtract 1
        return maxLength - 1;
    }
};

// Alternative approach
class SolutionAlternative {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeros = 0;
        int maxLen = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                zeros++;
            while (zeros > 1) {
                if (nums[left] == 0)
                    zeros--;
                left++;
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
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
    vector<int> nums1 = {1,1,0,1};
    cout << "Test 1: nums = ";
    printVector(nums1);
    cout << endl;
    cout << "Result: " << solution.longestSubarray(nums1) << endl;
    cout << "Alternative: " << solutionAlt.longestSubarray(nums1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {0,1,1,1,0,1,1,0,1};
    cout << "Test 2: nums = ";
    printVector(nums2);
    cout << endl;
    cout << "Result: " << solution.longestSubarray(nums2) << endl;
    cout << "Alternative: " << solutionAlt.longestSubarray(nums2) << endl;
    cout << "Expected: 5" << endl << endl;
    
    // Test case 3 - All ones (must delete one)
    vector<int> nums3 = {1,1,1};
    cout << "Test 3: nums = ";
    printVector(nums3);
    cout << endl;
    cout << "Result: " << solution.longestSubarray(nums3) << endl;
    cout << "Alternative: " << solutionAlt.longestSubarray(nums3) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 4 - All zeros
    vector<int> nums4 = {0,0,0};
    cout << "Test 4: nums = ";
    printVector(nums4);
    cout << endl;
    cout << "Result: " << solution.longestSubarray(nums4) << endl;
    cout << "Alternative: " << solutionAlt.longestSubarray(nums4) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test case 5 - Single element
    vector<int> nums5 = {1};
    cout << "Test 5: nums = ";
    printVector(nums5);
    cout << endl;
    cout << "Result: " << solution.longestSubarray(nums5) << endl;
    cout << "Alternative: " << solutionAlt.longestSubarray(nums5) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test case 6 - Alternating pattern
    vector<int> nums6 = {1,0,1,0,1,0,1};
    cout << "Test 6: nums = ";
    printVector(nums6);
    cout << endl;
    cout << "Result: " << solution.longestSubarray(nums6) << endl;
    cout << "Alternative: " << solutionAlt.longestSubarray(nums6) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 7 - Long sequence with one zero
    vector<int> nums7 = {1,1,1,1,0,1,1,1,1,1};
    cout << "Test 7: nums = ";
    printVector(nums7);
    cout << endl;
    cout << "Result: " << solution.longestSubarray(nums7) << endl;
    cout << "Alternative: " << solutionAlt.longestSubarray(nums7) << endl;
    cout << "Expected: 9" << endl;
    
    return 0;
}