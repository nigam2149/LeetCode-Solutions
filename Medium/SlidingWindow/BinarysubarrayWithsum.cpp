// Problem: Binary Subarrays With Sum
// Link: https://leetcode.com/problems/binary-subarrays-with-sum/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Prefix sum with frequency map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> mp;
        mp[0] = 1;
        int n = nums.size();
        int total = 0, prefix = 0;

        for(int i = 0; i < n; i++) {
            prefix += nums[i];

            // Check if (prefix - goal) exists in map
            if(mp.count(prefix - goal)) {
                total += mp[prefix - goal];
            }
            mp[prefix]++;
        }
        return total;
    }
};