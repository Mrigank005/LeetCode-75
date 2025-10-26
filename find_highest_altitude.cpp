#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = 0;
        
        // Calculate prefix sum and track maximum
        for (int i = 0; i < gain.size(); i++) {
            altitude += gain[i];
            maxAltitude = max(maxAltitude, altitude);
        }
        
        return maxAltitude;
    }
};

void printVector(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]";
}

void printAltitudes(const vector<int>& gain) {
    cout << "Altitudes: [0";
    int altitude = 0;
    for (int g : gain) {
        altitude += g;
        cout << "," << altitude;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> gain1 = {-5, 1, 5, 0, -7};
    cout << "Test 1: gain = ";
    printVector(gain1);
    cout << endl;
    printAltitudes(gain1);
    cout << "Result: " << solution.largestAltitude(gain1) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test case 2
    vector<int> gain2 = {-4, -3, -2, -1, 4, 3, 2};
    cout << "Test 2: gain = ";
    printVector(gain2);
    cout << endl;
    printAltitudes(gain2);
    cout << "Result: " << solution.largestAltitude(gain2) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test case 3 - All positive gains
    vector<int> gain3 = {1, 2, 3, 4, 5};
    cout << "Test 3: gain = ";
    printVector(gain3);
    cout << endl;
    printAltitudes(gain3);
    cout << "Result: " << solution.largestAltitude(gain3) << endl;
    cout << "Expected: 15" << endl << endl;
    
    // Test case 4 - All negative gains
    vector<int> gain4 = {-1, -2, -3, -4};
    cout << "Test 4: gain = ";
    printVector(gain4);
    cout << endl;
    printAltitudes(gain4);
    cout << "Result: " << solution.largestAltitude(gain4) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test case 5 - Single element
    vector<int> gain5 = {10};
    cout << "Test 5: gain = ";
    printVector(gain5);
    cout << endl;
    printAltitudes(gain5);
    cout << "Result: " << solution.largestAltitude(gain5) << endl;
    cout << "Expected: 10" << endl << endl;
    
    // Test case 6 - Peak in the middle
    vector<int> gain6 = {5, 3, -2, -8, 1, 2};
    cout << "Test 6: gain = ";
    printVector(gain6);
    cout << endl;
    printAltitudes(gain6);
    cout << "Result: " << solution.largestAltitude(gain6) << endl;
    cout << "Expected: 8" << endl;
    
    return 0;
}