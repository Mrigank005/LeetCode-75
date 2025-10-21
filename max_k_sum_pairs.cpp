#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Hash Map (OPTIMAL)
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int operations = 0;
        
        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        // Find pairs that sum to k
        for (auto& pair : freq) {
            int num = pair.first;
            int count = pair.second;
            int complement = k - num;
            
            if (complement == num) {
                // Special case: num + num = k
                operations += count / 2;
            } else if (freq.count(complement) && complement > num) {
                // Avoid double counting by only considering complement > num
                operations += min(count, freq[complement]);
            }
        }
        
        return operations;
    }
};

// Approach 2: Two Pointer (After sorting)
class SolutionTwoPointer {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.size() - 1;
        int operations = 0;
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum == k) {
                operations++;
                left++;
                right--;
            } else if (sum < k) {
                left++;   // Need larger sum
            } else {
                right--;  // Need smaller sum
            }
        }
        
        return operations;
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
    SolutionTwoPointer solutionTwoPointer;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 5;
    cout << "Test 1: nums = ";
    printVector(nums1);
    cout << ", k = " << k1 << endl;
    cout << "Hash Map: " << solution.maxOperations(nums1, k1) << endl;
    cout << "Two Pointer: " << solutionTwoPointer.maxOperations(nums1, k1) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {3, 1, 3, 4, 3};
    int k2 = 6;
    cout << "Test 2: nums = ";
    printVector(nums2);
    cout << ", k = " << k2 << endl;
    cout << "Hash Map: " << solution.maxOperations(nums2, k2) << endl;
    cout << "Two Pointer: " << solutionTwoPointer.maxOperations(nums2, k2) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test case 3 - Edge case: same numbers
    vector<int> nums3 = {2, 2, 2, 2};
    int k3 = 4;
    cout << "Test 3: nums = ";
    printVector(nums3);
    cout << ", k = " << k3 << endl;
    cout << "Hash Map: " << solution.maxOperations(nums3, k3) << endl;
    cout << "Two Pointer: " << solutionTwoPointer.maxOperations(nums3, k3) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 4 - Large numbers
    vector<int> nums4 = {1, 999999999, 1, 999999999};
    int k4 = 1000000000;
    cout << "Test 4: nums = ";
    printVector(nums4);
    cout << ", k = " << k4 << endl;
    cout << "Hash Map: " << solution.maxOperations(nums4, k4) << endl;
    cout << "Two Pointer: " << solutionTwoPointer.maxOperations(nums4, k4) << endl;
    cout << "Expected: 2" << endl;
    
    return 0;
}