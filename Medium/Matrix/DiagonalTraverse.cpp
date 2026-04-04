// Problem: Diagonal Traverse
// Link: https://leetcode.com/problems/diagonal-traverse/
// Difficulty: Medium
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Approach: Traverse diagonals, alternate direction up and down

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();

        for(int d = 0; d < n + m - 1; d++) {
            // Even diagonal - bottom to top
            if(d % 2 == 0) {
                int i = min(d, n - 1);
                int j = d - i;
                while(i >= 0 && j < m) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            // Odd diagonal - top to bottom
            else {
                int j = min(d, m - 1);
                int i = d - j;
                while(j >= 0 && i < n) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};