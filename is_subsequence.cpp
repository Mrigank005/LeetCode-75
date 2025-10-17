#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;  // Pointer for string s
        int j = 0;  // Pointer for string t
        
        while (j < t.length() && i < s.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        
        return i == s.length();
    }
};

// Alternative approach
class SolutionExplicit {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        
        int s_idx = 0;
        
        for (int j = 0; j < t.length(); j++) {
            if (t[j] == s[s_idx]) {
                s_idx++;
                
                if (s_idx == s.length()) {
                    return true;
                }
            }
        }
        
        return s_idx == s.length();
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "abc", t1 = "ahbgdc";
    cout << "Test 1: s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Output: " << (solution.isSubsequence(s1, t1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 2
    string s2 = "axc", t2 = "ahbgdc";
    cout << "Test 2: s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Output: " << (solution.isSubsequence(s2, t2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test case 3 - Empty s
    string s3 = "", t3 = "ahbgdc";
    cout << "Test 3: s = \"\", t = \"" << t3 << "\"" << endl;
    cout << "Output: " << (solution.isSubsequence(s3, t3) ? "true" : "false") << endl;
    cout << "Expected: true (empty string is always a subsequence)" << endl << endl;
    
    // Test case 4 - Single character match
    string s4 = "b", t4 = "abc";
    cout << "Test 4: s = \"" << s4 << "\", t = \"" << t4 << "\"" << endl;
    cout << "Output: " << (solution.isSubsequence(s4, t4) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 5 - All characters same
    string s5 = "aaa", t5 = "aaaaa";
    cout << "Test 5: s = \"" << s5 << "\", t = \"" << t5 << "\"" << endl;
    cout << "Output: " << (solution.isSubsequence(s5, t5) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    
    return 0;
}