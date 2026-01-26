// Problem: Pascal's Triangle
// Link: https://leetcode.com/problems/pascals-triangle/
// Difficulty: Easy
// Time Complexity: O(numRows^2)
// Space Complexity: O(numRows^2)

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int> row(i + 1, 1); // first and last element are 1
            for(int j = 1; j < i; j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j]; // sum of two elements above
            }
            ans.push_back(row);
        }
        return ans;
    }
};
