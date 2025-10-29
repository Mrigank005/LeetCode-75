#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Count frequencies
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // Check if all frequency values are unique
        unordered_set<int> uniqueCounts;
        for (auto& pair : freq) {
            if (uniqueCounts.count(pair.second) > 0) {
                return false;
            }
            uniqueCounts.insert(pair.second);
        }
        
        return true;
    }
};

// Alternative approach
class SolutionAlternative {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Count occurrences of each element using hash map
        unordered_map<int, int> countMap;
        for (int num : arr) {
            countMap[num]++;
        }
        
        // Step 2: Use hash set to check if occurrence counts are unique
        unordered_set<int> occurrences;
        for (auto& pair : countMap) {
            int count = pair.second;
            
            // If this count already exists, occurrences are not unique
            if (occurrences.find(count) != occurrences.end()) {
                return false;
            }
            
            // Add this count to the set
            occurrences.insert(count);
        }
        
        // All occurrence counts are unique
        return true;
    }
};

void printVector(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ",";
    }
    cout << "]";
}

void explainOccurrences(vector<int>& arr) {
    unordered_map<int, int> countMap;
    for (int num : arr) {
        countMap[num]++;
    }
    
    cout << "Occurrences: ";
    for (auto& pair : countMap) {
        cout << pair.first << "→" << pair.second << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    SolutionAlternative solutionAlt;
    
    // Test case 1
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Test 1: arr = ";
    printVector(arr1);
    cout << endl;
    explainOccurrences(arr1);
    cout << "Result: " << (solution.uniqueOccurrences(arr1) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.uniqueOccurrences(arr1) ? "true" : "false") << endl;
    cout << "Expected: true (1→3, 2→2, 3→1, all unique)" << endl << endl;
    
    // Test case 2
    vector<int> arr2 = {1, 2};
    cout << "Test 2: arr = ";
    printVector(arr2);
    cout << endl;
    explainOccurrences(arr2);
    cout << "Result: " << (solution.uniqueOccurrences(arr2) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.uniqueOccurrences(arr2) ? "true" : "false") << endl;
    cout << "Expected: false (1→1, 2→1, both have count 1)" << endl << endl;
    
    // Test case 3
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << "Test 3: arr = ";
    printVector(arr3);
    cout << endl;
    explainOccurrences(arr3);
    cout << "Result: " << (solution.uniqueOccurrences(arr3) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.uniqueOccurrences(arr3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 4 - All same elements
    vector<int> arr4 = {5, 5, 5, 5};
    cout << "Test 4: arr = ";
    printVector(arr4);
    cout << endl;
    explainOccurrences(arr4);
    cout << "Result: " << (solution.uniqueOccurrences(arr4) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.uniqueOccurrences(arr4) ? "true" : "false") << endl;
    cout << "Expected: true (5→4)" << endl << endl;
    
    // Test case 5 - Single element
    vector<int> arr5 = {1};
    cout << "Test 5: arr = ";
    printVector(arr5);
    cout << endl;
    explainOccurrences(arr5);
    cout << "Result: " << (solution.uniqueOccurrences(arr5) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.uniqueOccurrences(arr5) ? "true" : "false") << endl;
    cout << "Expected: true (1→1)" << endl << endl;
    
    // Test case 6 - Multiple same counts
    vector<int> arr6 = {1, 1, 2, 2, 3, 3};
    cout << "Test 6: arr = ";
    printVector(arr6);
    cout << endl;
    explainOccurrences(arr6);
    cout << "Result: " << (solution.uniqueOccurrences(arr6) ? "true" : "false") << endl;
    cout << "Alternative: " << (solutionAlt.uniqueOccurrences(arr6) ? "true" : "false") << endl;
    cout << "Expected: false (1→2, 2→2, 3→2, all have count 2)" << endl;
    
    return 0;
}