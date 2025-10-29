#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
        bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        
        // Use arrays for frequency counting (26 lowercase letters)
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char c : word1) {
            freq1[c - 'a']++;
        }
        for (char c : word2) {
            freq2[c - 'a']++;
        }
        
        // Check if both have same character set
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0) != (freq2[i] == 0)) {
                return false;
            }
        }
        
        // Check if frequency distributions match
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2;
    }
};

// Alternative approach: Using Hashmap
class SolutionAlternative {
public:
    bool closeStrings(string word1, string word2) {
        // Condition 1: Both strings must have same length
        if (word1.length() != word2.length()) {
            return false;
        }
        
        // Count frequency of each character in both strings
        unordered_map<char, int> freq1, freq2;
        for (char c : word1) {
            freq1[c]++;
        }
        for (char c : word2) {
            freq2[c]++;
        }
        
        // Condition 2: Both strings must have same set of characters
        if (freq1.size() != freq2.size()) {
            return false;
        }
        
        for (auto& pair : freq1) {
            if (freq2.find(pair.first) == freq2.end()) {
                return false;
            }
        }
        
        // Condition 3: Both strings must have same frequency distribution
        // Extract frequency values and sort them
        vector<int> counts1, counts2;
        for (auto& pair : freq1) {
            counts1.push_back(pair.second);
        }
        for (auto& pair : freq2) {
            counts2.push_back(pair.second);
        }
        
        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());
        
        return counts1 == counts2;
    }
};

void printFrequencyMap(const unordered_map<char, int>& freq) {
    cout << "{";
    bool first = true;
    for (auto& pair : freq) {
        if (!first) cout << ", ";
        cout << pair.first << ":" << pair.second;
        first = false;
    }
    cout << "}";
}

void explainClose(string word1, string word2) {
    unordered_map<char, int> freq1, freq2;
    for (char c : word1) freq1[c]++;
    for (char c : word2) freq2[c]++;
    
    cout << "word1 frequencies: ";
    printFrequencyMap(freq1);
    cout << endl;
    
    cout << "word2 frequencies: ";
    printFrequencyMap(freq2);
    cout << endl;
    
    vector<int> counts1, counts2;
    for (auto& p : freq1) counts1.push_back(p.second);
    for (auto& p : freq2) counts2.push_back(p.second);
    
    sort(counts1.begin(), counts1.end());
    sort(counts2.begin(), counts2.end());
    
    cout << "Sorted counts word1: [";
    for (int i = 0; i < counts1.size(); i++) {
        cout << counts1[i];
        if (i < counts1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "Sorted counts word2: [";
    for (int i = 0; i < counts2.size(); i++) {
        cout << counts2[i];
        if (i < counts2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    SolutionAlternative solutionAlt;
    
    // Test case 1
    string word1_1 = "abc", word2_1 = "bca";
    cout << "Test 1: word1 = \"" << word1_1 << "\", word2 = \"" << word2_1 << "\"" << endl;
    explainClose(word1_1, word2_1);
    cout << "Result: " << (solution.closeStrings(word1_1, word2_1) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.closeStrings(word1_1, word2_1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 2
    string word1_2 = "a", word2_2 = "aa";
    cout << "Test 2: word1 = \"" << word1_2 << "\", word2 = \"" << word2_2 << "\"" << endl;
    explainClose(word1_2, word2_2);
    cout << "Result: " << (solution.closeStrings(word1_2, word2_2) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.closeStrings(word1_2, word2_2) ? "true" : "false") << endl;
    cout << "Expected: false (different lengths)" << endl << endl;
    
    // Test case 3
    string word1_3 = "cabbba", word2_3 = "abbccc";
    cout << "Test 3: word1 = \"" << word1_3 << "\", word2 = \"" << word2_3 << "\"" << endl;
    explainClose(word1_3, word2_3);
    cout << "Result: " << (solution.closeStrings(word1_3, word2_3) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.closeStrings(word1_3, word2_3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 4 - Different character sets
    string word1_4 = "abc", word2_4 = "def";
    cout << "Test 4: word1 = \"" << word1_4 << "\", word2 = \"" << word2_4 << "\"" << endl;
    explainClose(word1_4, word2_4);
    cout << "Result: " << (solution.closeStrings(word1_4, word2_4) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.closeStrings(word1_4, word2_4) ? "true" : "false") << endl;
    cout << "Expected: false (different character sets)" << endl << endl;
    
    // Test case 5 - Same frequencies, different char sets
    string word1_5 = "uau", word2_5 = "ssx";
    cout << "Test 5: word1 = \"" << word1_5 << "\", word2 = \"" << word2_5 << "\"" << endl;
    explainClose(word1_5, word2_5);
    cout << "Result: " << (solution.closeStrings(word1_5, word2_5) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.closeStrings(word1_5, word2_5) ? "true" : "false") << endl;
    cout << "Expected: false (different character sets)" << endl << endl;
    
    // Test case 6 - Complex transformation
    string word1_6 = "abbzzca", word2_6 = "babzzcz";
    cout << "Test 6: word1 = \"" << word1_6 << "\", word2 = \"" << word2_6 << "\"" << endl;
    explainClose(word1_6, word2_6);
    cout << "Result: " << (solution.closeStrings(word1_6, word2_6) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.closeStrings(word1_6, word2_6) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    
    return 0;
}