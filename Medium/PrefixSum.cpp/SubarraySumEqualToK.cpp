// Problem: Longest Subarray with Sum K
// Link: https://www.geeksforgeeks.org/longest-sub-array-sum-k/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Prefix sum with hash map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;  // (prefix_sum, first_index)
        int ans = 0;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // If sum from start equals k
            if(sum == k) {
                ans = i + 1;
            }
            
            // If (sum - k) found before, we have a subarray with sum k
            if(mp.find(sum - k) != mp.end()) {
                ans = max(ans, i - mp[sum - k]);
            }
            
            // Store first occurrence of this sum
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return ans;
    }
};