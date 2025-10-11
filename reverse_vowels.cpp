#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer until we find a vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            
            // Move right pointer until we find a vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            
            // Swap vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "IceCreAm";
    cout << "Test 1: " << s1 << " -> " << solution.reverseVowels(s1) << endl;
    cout << "Expected: AceCreIm" << endl << endl;
    
    // Test case 2
    string s2 = "leetcode";
    cout << "Test 2: " << s2 << " -> " << solution.reverseVowels(s2) << endl;
    cout << "Expected: leotcede" << endl << endl;
    
    // Test case 3 - Edge case: single vowel
    string s3 = "a";
    cout << "Test 3: " << s3 << " -> " << solution.reverseVowels(s3) << endl;
    cout << "Expected: a" << endl << endl;
    
    // Test case 4 - Edge case: no vowels
    string s4 = "bcdfg";
    cout << "Test 4: " << s4 << " -> " << solution.reverseVowels(s4) << endl;
    cout << "Expected: bcdfg" << endl << endl;
    
    // Test case 5 - Edge case: all vowels
    string s5 = "aeiou";
    cout << "Test 5: " << s5 << " -> " << solution.reverseVowels(s5) << endl;
    cout << "Expected: uoiea" << endl;
    
    return 0;
}