#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Using prefix and suffix arrays 
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n), result(n);
        
        // Build prefix array before i
        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        
        // Build suffix array after i
        suffix[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        
        // Combine prefix and suffix
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }
        
        return result;
    }
};

// Approach 2: Using output array for prefix
class SolutionOptimized {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        // Step 1: Store prefix products in result array
        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = result[i-1] * nums[i-1];
        }
        
        // Step 2: Multiply with suffix products on the fly
        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        
        return result;
    }
};

void printArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution solution;
    SolutionOptimized optimized;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Test 1: nums = ";
    printArray(nums1);
    cout << endl;
    
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Output (Basic): ";
    printArray(result1);
    cout << endl;
    
    vector<int> result1_opt = optimized.productExceptSelf(nums1);
    cout << "Output (Optimized): ";
    printArray(result1_opt);
    cout << endl;
    cout << "Expected: [24, 12, 8, 6]" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "Test 2: nums = ";
    printArray(nums2);
    cout << endl;
    
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Output (Basic): ";
    printArray(result2);
    cout << endl;
    
    vector<int> result2_opt = optimized.productExceptSelf(nums2);
    cout << "Output (Optimized): ";
    printArray(result2_opt);
    cout << endl;
    cout << "Expected: [0, 0, 9, 0, 0]" << endl << endl;
    
    // Test case 3 - Edge case
    vector<int> nums3 = {2, 3};
    cout << "Test 3: nums = ";
    printArray(nums3);
    cout << endl;
    
    vector<int> result3 = optimized.productExceptSelf(nums3);
    cout << "Output: ";
    printArray(result3);
    cout << endl;
    cout << "Expected: [3, 2]" << endl;
    
    return 0;
}