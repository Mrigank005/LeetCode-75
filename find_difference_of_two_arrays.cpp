#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Create sets to store unique elements from both arrays
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> diff1; // Elements in nums1 but not in nums2
        vector<int> diff2; // Elements in nums2 but not in nums1
        
        // Find elements in set1 that are not in set2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                diff1.push_back(num);
            }
        }
        
        // Find elements in set2 that are not in set1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                diff2.push_back(num);
            }
        }
        
        return {diff1, diff2};
    }
};

// Alternative approach: More explicit
class SolutionAlternative {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        
        // Build sets from arrays (automatically handles duplicates)
        for (int num : nums1) {
            set1.insert(num);
        }
        
        for (int num : nums2) {
            set2.insert(num);
        }
        
        vector<vector<int>> result(2);
        
        // Find unique elements in nums1
        for (int num : set1) {
            if (set2.count(num) == 0) {
                result[0].push_back(num);
            }
        }
        
        // Find unique elements in nums2
        for (int num : set2) {
            if (set1.count(num) == 0) {
                result[1].push_back(num);
            }
        }
        
        return result;
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

void printResult(const vector<vector<int>>& result) {
    cout << "[";
    printVector(result[0]);
    cout << ",";
    printVector(result[1]);
    cout << "]";
}

int main() {
    Solution solution;
    SolutionAlternative solutionAlt;
    
    // Test case 1
    vector<int> nums1_1 = {1, 2, 3};
    vector<int> nums2_1 = {2, 4, 6};
    cout << "Test 1:" << endl;
    cout << "nums1 = ";
    printVector(nums1_1);
    cout << ", nums2 = ";
    printVector(nums2_1);
    cout << endl;
    cout << "Result: ";
    printResult(solution.findDifference(nums1_1, nums2_1));
    cout << endl;
    cout << "Alternative: ";
    printResult(solutionAlt.findDifference(nums1_1, nums2_1));
    cout << endl;
    cout << "Expected: [[1,3],[4,6]]" << endl << endl;
    
    // Test case 2
    vector<int> nums1_2 = {1, 2, 3, 3};
    vector<int> nums2_2 = {1, 1, 2, 2};
    cout << "Test 2:" << endl;
    cout << "nums1 = ";
    printVector(nums1_2);
    cout << ", nums2 = ";
    printVector(nums2_2);
    cout << endl;
    cout << "Result: ";
    printResult(solution.findDifference(nums1_2, nums2_2));
    cout << endl;
    cout << "Alternative: ";
    printResult(solutionAlt.findDifference(nums1_2, nums2_2));
    cout << endl;
    cout << "Expected: [[3],[]]" << endl << endl;
    
    // Test case 3 - Empty result for first array
    vector<int> nums1_3 = {1, 2};
    vector<int> nums2_3 = {1, 2, 3};
    cout << "Test 3:" << endl;
    cout << "nums1 = ";
    printVector(nums1_3);
    cout << ", nums2 = ";
    printVector(nums2_3);
    cout << endl;
    cout << "Result: ";
    printResult(solution.findDifference(nums1_3, nums2_3));
    cout << endl;
    cout << "Alternative: ";
    printResult(solutionAlt.findDifference(nums1_3, nums2_3));
    cout << endl;
    cout << "Expected: [[],[3]]" << endl << endl;
    
    // Test case 4 - No common elements
    vector<int> nums1_4 = {1, 3, 5};
    vector<int> nums2_4 = {2, 4, 6};
    cout << "Test 4:" << endl;
    cout << "nums1 = ";
    printVector(nums1_4);
    cout << ", nums2 = ";
    printVector(nums2_4);
    cout << endl;
    cout << "Result: ";
    printResult(solution.findDifference(nums1_4, nums2_4));
    cout << endl;
    cout << "Alternative: ";
    printResult(solutionAlt.findDifference(nums1_4, nums2_4));
    cout << endl;
    cout << "Expected: [[1,3,5],[2,4,6]]" << endl << endl;
    
    // Test case 5 - All common elements
    vector<int> nums1_5 = {1, 2, 3};
    vector<int> nums2_5 = {3, 2, 1};
    cout << "Test 5:" << endl;
    cout << "nums1 = ";
    printVector(nums1_5);
    cout << ", nums2 = ";
    printVector(nums2_5);
    cout << endl;
    cout << "Result: ";
    printResult(solution.findDifference(nums1_5, nums2_5));
    cout << endl;
    cout << "Alternative: ";
    printResult(solutionAlt.findDifference(nums1_5, nums2_5));
    cout << endl;
    cout << "Expected: [[],[]]" << endl << endl;
    
    // Test case 6 - Negative numbers
    vector<int> nums1_6 = {-5, -3, 0, 2};
    vector<int> nums2_6 = {-3, 0, 5, 10};
    cout << "Test 6:" << endl;
    cout << "nums1 = ";
    printVector(nums1_6);
    cout << ", nums2 = ";
    printVector(nums2_6);
    cout << endl;
    cout << "Result: ";
    printResult(solution.findDifference(nums1_6, nums2_6));
    cout << endl;
    cout << "Alternative: ";
    printResult(solutionAlt.findDifference(nums1_6, nums2_6));
    cout << endl;
    cout << "Expected: [[-5,2],[5,10]]" << endl;
    
    return 0;
}