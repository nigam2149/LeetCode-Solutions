// Problem: Rotate Matrix by 180 Degrees
// Link: https://www.geeksforgeeks.org/problems/rotate-by-90-degree/1
// Difficulty: Easy
// Time Complexity: O(n*n)
// Space Complexity: O(1)
// Approach: 90 degree rotation twice (Transpose + Reverse, twice)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // First 90 degree rotation
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            int st = 0, end = n - 1;
            while(st < end) {
                swap(matrix[i][st], matrix[i][end]);
                st++;
                end--;
            }
        }

        // Second 90 degree rotation
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            int st = 0, end = n - 1;
            while(st < end) {
                swap(matrix[i][st], matrix[i][end]);
                st++;
                end--;
            }
        }
    }
};