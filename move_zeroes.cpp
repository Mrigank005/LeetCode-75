#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;  // Pointer for next position of non-zero element
        
        // Move non-zero elements forward and swap with zeros
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

void printArray(const vector<int>& nums) {
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
    vector<int> nums1 = {0, 1, 0, 3, 12};
    cout << "Test 1: ";
    printArray(nums1);
    solution.moveZeroes(nums1);
    cout << " -> ";
    printArray(nums1);
    cout << endl;
    cout << "Expected: [1, 3, 12, 0, 0]" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {0};
    cout << "Test 2: ";
    printArray(nums2);
    solution.moveZeroes(nums2);
    cout << " -> ";
    printArray(nums2);
    cout << endl;
    cout << "Expected: [0]" << endl << endl;
    
    // Test case 3 - No zeros
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test 3: ";
    printArray(nums3);
    solution.moveZeroes(nums3);
    cout << " -> ";
    printArray(nums3);
    cout << endl;
    cout << "Expected: [1, 2, 3, 4, 5]" << endl << endl;
    
    // Test case 4 - All zeros
    vector<int> nums4 = {0, 0, 0, 0};
    cout << "Test 4: ";
    printArray(nums4);
    solution.moveZeroes(nums4);
    cout << " -> ";
    printArray(nums4);
    cout << endl;
    cout << "Expected: [0, 0, 0, 0]" << endl << endl;
    
    return 0;
}