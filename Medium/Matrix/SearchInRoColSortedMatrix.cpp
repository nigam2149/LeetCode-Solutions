// Problem: Search in a Row-Column Sorted Matrix
// Link: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
// Difficulty: Medium
// Time Complexity: O(n+m)
// Space Complexity: O(1)
// Approach: Start from top-right, eliminate row or column each step

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;

        while(i < m && j >= 0) {
            int num = matrix[i][j];

            if(num == target) {
                return true;
            } else if(num > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};