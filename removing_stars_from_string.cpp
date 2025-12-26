#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string result;  // Use string as a stack
        
        // Iterate through each character in the string
        for (char c : s) {
            if (c == '*') {
                // Remove the closest non-star character (pop from stack)
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                // Add non-star character to stack
                result.push_back(c);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "leet**cod*e";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.removeStars(s1) << endl;
    cout << "Expected: lecoe" << endl << endl;
    
    // Example 2
    string s2 = "erase*****";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.removeStars(s2) << endl;
    cout << "Expected: (empty string)" << endl;
    
    return 0;
}
