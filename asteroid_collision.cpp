#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            bool alive = true;
            
            // Only process collisions if current asteroid is moving left (negative)
            // and there are right-moving asteroids (positive) in the stack
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                // Compare sizes
                if (st.top() < -asteroid) {
                    // Top asteroid explodes, continue checking
                    st.pop();
                    continue;
                } else if (st.top() == -asteroid) {
                    // Both asteroids explode
                    st.pop();
                }
                // If st.top() > -asteroid, current asteroid explodes
                alive = false;
                break;
            }
            
            // Add asteroid to stack if it survived
            if (alive) {
                st.push(asteroid);
            }
        }
        
        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // Example 1
    vector<int> asteroids1 = {5, 10, -5};
    cout << "Input: ";
    printVector(asteroids1);
    vector<int> result1 = sol.asteroidCollision(asteroids1);
    cout << "Output: ";
    printVector(result1);
    cout << "Expected: [5, 10]" << endl << endl;
    
    // Example 2
    vector<int> asteroids2 = {8, -8};
    cout << "Input: ";
    printVector(asteroids2);
    vector<int> result2 = sol.asteroidCollision(asteroids2);
    cout << "Output: ";
    printVector(result2);
    cout << "Expected: []" << endl << endl;
    
    // Example 3
    vector<int> asteroids3 = {10, 2, -5};
    cout << "Input: ";
    printVector(asteroids3);
    vector<int> result3 = sol.asteroidCollision(asteroids3);
    cout << "Output: ";
    printVector(result3);
    cout << "Expected: [10]" << endl << endl;
    
    // Example 4
    vector<int> asteroids4 = {3, 5, -6, 2, -1, 4};
    cout << "Input: ";
    printVector(asteroids4);
    vector<int> result4 = sol.asteroidCollision(asteroids4);
    cout << "Output: ";
    printVector(result4);
    cout << "Expected: [-6, 2, 4]" << endl << endl;
    
    // Your example
    vector<int> asteroids5 = {5, 10, -5, -15};
    cout << "Input: ";
    printVector(asteroids5);
    vector<int> result5 = sol.asteroidCollision(asteroids5);
    cout << "Output: ";
    printVector(result5);
    cout << "Expected: [-15]" << endl;
    
    return 0;
}
