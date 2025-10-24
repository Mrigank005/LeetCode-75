#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        // Count vowels in first window of size k
        int currentVowels = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                currentVowels++;
            }
        }
        
        int maxVowels = currentVowels;
        
        // Slide the window
        for (int i = k; i < s.length(); i++) {
            // Remove the character that's sliding out of the window
            if (isVowel(s[i - k])) {
                currentVowels--;
            }
            
            // Add the new character that's sliding into the window
            if (isVowel(s[i])) {
                currentVowels++;
            }
            
            // Update maximum vowels found
            maxVowels = max(maxVowels, currentVowels);
        }
        
        return maxVowels;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "abciiidef";
    int k1 = 3;
    cout << "Test 1: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Result: " << solution.maxVowels(s1, k1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test case 2
    string s2 = "aeiou";
    int k2 = 2;
    cout << "Test 2: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Result: " << solution.maxVowels(s2, k2) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 3
    string s3 = "leetcode";
    int k3 = 3;
    cout << "Test 3: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Result: " << solution.maxVowels(s3, k3) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test case 4 - All consonants
    string s4 = "rhythms";
    int k4 = 4;
    cout << "Test 4: s = \"" << s4 << "\", k = " << k4 << endl;
    cout << "Result: " << solution.maxVowels(s4, k4) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test case 5 - Single character
    string s5 = "a";
    int k5 = 1;
    cout << "Test 5: s = \"" << s5 << "\", k = " << k5 << endl;
    cout << "Result: " << solution.maxVowels(s5, k5) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test case 6 - Long string with pattern
    string s6 = "weallloveyou";
    int k6 = 7;
    cout << "Test 6: s = \"" << s6 << "\", k = " << k6 << endl;
    cout << "Result: " << solution.maxVowels(s6, k6) << endl;
    cout << "Expected: 4" << endl;
    
    return 0;
}