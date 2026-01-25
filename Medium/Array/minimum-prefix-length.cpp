// Problem: Minimum Prefix Length
// Link: https://leetcode.com/submissions/detail/1896698442/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] <= nums[i - 1]) {
                return i;
            }
        }
        return 0;
    }
};