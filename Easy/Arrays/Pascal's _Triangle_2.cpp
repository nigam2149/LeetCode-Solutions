// Problem: Pascal's Triangle II
// Link: https://leetcode.com/problems/pascals-triangle-ii/
// Difficulty: Easy
// Time Complexity: O(k^2), where k = rowIndex
// Space Complexity: O(k^2) (or O(k) for optimized version)
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        for(int i = 0; i <= rowIndex; i++){
            vector<int> row(i+1, 1); // first and last element are 1
            for(int j = 1; j < i; j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j]; // sum of two elements above
            }
            ans.push_back(row);
        }
        return ans[rowIndex];
    }
};
