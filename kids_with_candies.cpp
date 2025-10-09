#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Step 1: Find maxCandies using manual loop
        int maxCandies = candies[0];
        for (int i = 1; i < candies.size(); i++) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }
        
        // Step 2: Check each kid and store boolean results
        vector<bool> result;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    vector<bool> result1 = solution.kidsWithCandies(candies1, extraCandies1);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << (result1[i] ? "true" : "false");
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl; // Expected: [true, true, true, false, true]
    
    // Test case 2
    vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;
    vector<bool> result2 = solution.kidsWithCandies(candies2, extraCandies2);
    cout << "Test 2: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << (result2[i] ? "true" : "false");
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl; // Expected: [true, false, false, false, false]
    
    // Test case 3
    vector<int> candies3 = {12, 1, 12};
    int extraCandies3 = 10;
    vector<bool> result3 = solution.kidsWithCandies(candies3, extraCandies3);
    cout << "Test 3: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << (result3[i] ? "true" : "false");
        if (i < result3.size() - 1) cout << ", ";
    }
    cout << "]" << endl; // Expected: [true, false, true]
    
    return 0;
}