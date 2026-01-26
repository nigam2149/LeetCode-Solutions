// Problem: Minimum Absolute Difference
// Link: https://leetcode.com/problems/minimum-absolute-difference/
// Difficulty: Easy
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        
        for(int i = 1; i < arr.size(); i++) {
            minDiff = min(minDiff, arr[i] - arr[i-1]);
        }
        
        for(int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i-1];
            if(diff == minDiff) {
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        
        return ans;        
    }
};