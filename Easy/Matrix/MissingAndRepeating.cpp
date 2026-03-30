// Problem: Find Missing and Repeated Values
// Link: https://leetcode.com/problems/find-missing-and-repeated-values/
// Difficulty: Medium
// Time Complexity: O(n*n)
// Space Complexity: O(n*n)
// Approach: Frequency map, find element with freq 2 and freq 0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> mp;
        vector<int> ans(2);

        // Count frequency of all elements
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[grid[i][j]]++;
            }
        }

        // Find repeating (freq=2) and missing (freq=0)
        for(int i = 1; i <= n * n; i++) {
            if(mp[i] == 2)      ans[0] = i;
            else if(mp[i] == 0) ans[1] = i;
        }

        return ans;
    }
};