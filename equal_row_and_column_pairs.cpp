#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rowMap;
        
        // Store all rows in the map with their frequencies
        for (int i = 0; i < n; i++) {
            rowMap[grid[i]]++;
        }
        
        int count = 0;
        
        // For each column, check if it exists as a row
        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            
            // If this column matches any row(s), add the frequency
            if (rowMap.find(col) != rowMap.end()) {
                count += rowMap[col];
            }
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<vector<int>> grid1 = {{3,2,1},{1,7,6},{2,7,7}};
    cout << "Example 1 Output: " << solution.equalPairs(grid1) << endl;
    // Expected: 1
    
    // Example 2
    vector<vector<int>> grid2 = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout << "Example 2 Output: " << solution.equalPairs(grid2) << endl;
    // Expected: 3
    
    return 0;
}
