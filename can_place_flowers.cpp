#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                
                bool rightEmpty = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    count++;
                    
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        
        return count >= n;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    cout << "Test 1: flowerbed = [1,0,0,0,1], n = " << n1 << endl;
    cout << "Result: " << (solution.canPlaceFlowers(flowerbed1, n1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test case 2 
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;
    cout << "Test 2: flowerbed = [1,0,0,0,1], n = " << n2 << endl;
    cout << "Result: " << (solution.canPlaceFlowers(flowerbed2, n2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test case 3 - Edge case: all zeros
    vector<int> flowerbed3 = {0, 0, 0, 0, 0};
    int n3 = 3;
    cout << "Test 3: flowerbed = [0,0,0,0,0], n = " << n3 << endl;
    cout << "Result: " << (solution.canPlaceFlowers(flowerbed3, n3) ? "true" : "false") << endl;
    cout << "Expected: true (can plant at positions 0, 2, 4)" << endl << endl;
    
    // Test case 4 - Edge case: single element
    vector<int> flowerbed4 = {0};
    int n4 = 1;
    cout << "Test 4: flowerbed = [0], n = " << n4 << endl;
    cout << "Result: " << (solution.canPlaceFlowers(flowerbed4, n4) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    
    return 0;
}
