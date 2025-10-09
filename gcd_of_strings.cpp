#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenating in both orders gives different results, no common divisor
        if (str1 + str2 != str2 + str1) return "";
        // The GCD of the lengths gives the largest possible substring
        int gcdLen = gcd(str1.length(), str2.length());
        return str1.substr(0, gcdLen);
    }
private:
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution solution;
    // Test case 1
    string str1 = "ABCABC", str2 = "ABC";
    cout << "Test 1: " << solution.gcdOfStrings(str1, str2) << endl; // Output: "ABC"
    // Test case 2
    str1 = "ABABAB", str2 = "ABAB";
    cout << "Test 2: " << solution.gcdOfStrings(str1, str2) << endl; // Output: "AB"
    // Test case 3
    str1 = "LEET", str2 = "CODE";
    cout << "Test 3: " << solution.gcdOfStrings(str1, str2) << endl; // Output: ""
    return 0;
}