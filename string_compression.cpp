#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;  // Write pointer for compressed result
        int i = 0;      // Read pointer
        int n = chars.size();
        
        while (i < n) {
            char currentChar = chars[i];
            int count = 0;
            
            // Count consecutive occurrences of current character
            while (i < n && chars[i] == currentChar) {
                i++;
                count++;
            }
            
            // Write the character
            chars[write++] = currentChar;
            
            // Write the count if greater than 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }
        
        return write;
    }
};

// Helper function to print the compressed array
void printArray(const vector<char>& chars, int len) {
    cout << "[";
    for (int i = 0; i < len; i++) {
        cout << "\"" << chars[i] << "\"";
        if (i < len - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << "Test 1: [\"a\",\"a\",\"b\",\"b\",\"c\",\"c\",\"c\"]" << endl;
    int len1 = solution.compress(chars1);
    cout << "Output: Return " << len1 << ", array = ";
    printArray(chars1, len1);
    cout << endl;
    cout << "Expected: Return 6, array = [\"a\",\"2\",\"b\",\"2\",\"c\",\"3\"]" << endl << endl;
    
    // Test case 2
    vector<char> chars2 = {'a'};
    cout << "Test 2: [\"a\"]" << endl;
    int len2 = solution.compress(chars2);
    cout << "Output: Return " << len2 << ", array = ";
    printArray(chars2, len2);
    cout << endl;
    cout << "Expected: Return 1, array = [\"a\"]" << endl << endl;
    
    // Test case 3
    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    cout << "Test 3: [\"a\",\"b\",\"b\",\"b\",\"b\",\"b\",\"b\",\"b\",\"b\",\"b\",\"b\",\"b\",\"b\"]" << endl;
    int len3 = solution.compress(chars3);
    cout << "Output: Return " << len3 << ", array = ";
    printArray(chars3, len3);
    cout << endl;
    cout << "Expected: Return 4, array = [\"a\",\"b\",\"1\",\"2\"]" << endl << endl;
    
    // Test case 4 - Edge case: all same characters
    vector<char> chars4 = {'a', 'a', 'a', 'a', 'a'};
    cout << "Test 4: [\"a\",\"a\",\"a\",\"a\",\"a\"]" << endl;
    int len4 = solution.compress(chars4);
    cout << "Output: Return " << len4 << ", array = ";
    printArray(chars4, len4);
    cout << endl;
    cout << "Expected: Return 2, array = [\"a\",\"5\"]" << endl << endl;
    
    // Test case 5 - Edge case: count = 100 (multi-digit)
    vector<char> chars5(100, 'a');
    cout << "Test 5: 100 'a's" << endl;
    int len5 = solution.compress(chars5);
    cout << "Output: Return " << len5 << ", array = ";
    printArray(chars5, len5);
    cout << endl;
    cout << "Expected: Return 4, array = [\"a\",\"1\",\"0\",\"0\"]" << endl;
    
    return 0;
}