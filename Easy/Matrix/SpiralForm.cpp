// Problem: Spiral Matrix
// Link: https://leetcode.com/problems/spiral-matrix/
// Difficulty: Medium
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Approach: Four boundaries - top, bottom, left, right, shrink after each traversal

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0, right = col - 1, bottom = row - 1, left = 0;

        while(top <= bottom && left <= right) {

            // Left to right
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Top to bottom
            for(int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Right to left
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Bottom to top
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};