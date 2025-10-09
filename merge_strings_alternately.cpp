#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0, j = 0;
        
        // Merge characters alternately while both strings have characters
        while (i < word1.length() && j < word2.length()) {
            result += word1[i++];
            result += word2[j++];
        }
        
        // Append remaining characters from word1 if any
        while (i < word1.length()) {
            result += word1[i++];
        }
        
        // Append remaining characters from word2 if any
        while (j < word2.length()) {
            result += word2[j++];
        }
        
        return result;
    }
};

// Test function to verify the solution
int main() {
    Solution solution;
    
    // Test case 1
    string word1 = "abc", word2 = "pqr";
    cout << "Test 1: " << solution.mergeAlternately(word1, word2) << endl;
    // Expected: "apbqcr"
    
    // Test case 2
    word1 = "ab", word2 = "pqrs";
    cout << "Test 2: " << solution.mergeAlternately(word1, word2) << endl;
    // Expected: "apbqrs"
    
    // Test case 3
    word1 = "abcd", word2 = "pq";
    cout << "Test 3: " << solution.mergeAlternately(word1, word2) << endl;
    // Expected: "apbqcd"
    
    return 0;
}