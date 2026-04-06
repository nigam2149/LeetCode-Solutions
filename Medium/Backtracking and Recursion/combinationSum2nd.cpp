// Problem: Combination Sum II
// Link: https://leetcode.com/problems/combination-sum-ii/
// Difficulty: Medium
// Time Complexity: O(2^n)
// Space Complexity: O(n) - recursion stack
// Approach: Recursion, include or skip duplicates at each step

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void combinations(vector<int>& candidates, int indx, int tar,
                      vector<vector<int>>& ans, vector<int>& temp) {
        if(tar == 0) {
            ans.push_back(temp);
            return;
        }
        if(indx == candidates.size() || tar < 0) return;

        // Include current element
        temp.push_back(candidates[indx]);
        combinations(candidates, indx + 1, tar - candidates[indx], ans, temp);
        temp.pop_back();

        // Skip duplicates
        int i = indx + 1;
        while(i < candidates.size() && candidates[i] == candidates[i - 1]) i++;
        combinations(candidates, i, tar, ans, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combinations(candidates, 0, target, ans, temp);
        return ans;
    }
};