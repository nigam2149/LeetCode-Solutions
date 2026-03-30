// Problem: Search a 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/
// Difficulty: Medium
// Time Complexity: O(log(m*n))
// Space Complexity: O(1)
// Approach: Treat matrix as 1D sorted array, binary search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int st = 0, end = m * n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            // Convert mid to row and col
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) {
                return true;
            } else if(matrix[row][col] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return false;
    }
};