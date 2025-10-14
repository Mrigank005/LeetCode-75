#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;   // Smallest value seen so far
        int second = INT_MAX;  // Smallest value greater than 'first'
        
        for (int num : nums) {
            if (num <= first) {
                first = num;  // Update smallest
            }
            else if (num <= second) {
                second = num;  // Update second smallest (greater than first)
            }
            else {
                // Found num > second > first, we have our triplet!
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Test 1: [1, 2, 3, 4, 5]" << endl;
    cout << "Output: " << (solution.increasingTriplet(nums1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << "Test 2: [5, 4, 3, 2, 1]" << endl;
    cout << "Output: " << (solution.increasingTriplet(nums2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    cout << "Test 3: [2, 1, 5, 0, 4, 6]" << endl;
    cout << "Output: " << (solution.increasingTriplet(nums3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 4 - Edge case
    vector<int> nums4 = {20, 100, 10, 12, 5, 13};
    cout << "Test 4: [20, 100, 10, 12, 5, 13]" << endl;
    cout << "Output: " << (solution.increasingTriplet(nums4) ? "true" : "false") << endl;
    cout << "Expected: true (triplet: 10 < 12 < 13)" << endl << endl;
    
    // Test case 5 - Edge case: exactly 3 elements
    vector<int> nums5 = {1, 2, 0};
    cout << "Test 5: [1, 2, 0]" << endl;
    cout << "Output: " << (solution.increasingTriplet(nums5) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    
    return 0;
}