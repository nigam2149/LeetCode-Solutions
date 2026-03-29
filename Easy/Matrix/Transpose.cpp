// Problem: Transpose of a Matrix
// Link: https://www.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1
// Difficulty: Easy
// Time Complexity: O(n*n)
// Space Complexity: O(1)
// Approach: Swap upper triangle with lower triangle

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void transpose(vector<vector<int>>& matrix, int n) {
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};