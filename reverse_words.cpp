#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int n = s.length();
        int i = n - 1;
        
        while (i >= 0) {
            // Skip trailing spaces
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            
            if (i < 0) break; // No more words
            
            // Find the start of current word
            int j = i;
            while (i >= 0 && s[i] != ' ') {
                i--;
            }
            
            // Add word to result (i+1 to j inclusive)
            if (!result.empty()) {
                result += " ";
            }
            result += s.substr(i + 1, j - i);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "the sky is blue";
    cout << "Test 1: \"" << s1 << "\"" << endl;
    cout << "Output: \"" << solution.reverseWords(s1) << "\"" << endl;
    cout << "Expected: \"blue is sky the\"" << endl << endl;
    
    // Test case 2
    string s2 = "  hello world  ";
    cout << "Test 2: \"" << s2 << "\"" << endl;
    cout << "Output: \"" << solution.reverseWords(s2) << "\"" << endl;
    cout << "Expected: \"world hello\"" << endl << endl;
    
    // Test case 3
    string s3 = "a good   example";
    cout << "Test 3: \"" << s3 << "\"" << endl;
    cout << "Output: \"" << solution.reverseWords(s3) << "\"" << endl;
    cout << "Expected: \"example good a\"" << endl << endl;
    
    // Test case 4 - Edge case: single word
    string s4 = "hello";
    cout << "Test 4: \"" << s4 << "\"" << endl;
    cout << "Output: \"" << solution.reverseWords(s4) << "\"" << endl;
    cout << "Expected: \"hello\"" << endl;
    
    return 0;
}