// Problem: Maximum Length Subarray With at Most K Frequency
// Link: https://leetcode.com/problems/maximum-length-subarray-with-at-most-k-frequency/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Sliding window with frequency map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int start=0, end=0, n=nums.size(), len=0;

        while(end < n) {
            mp[nums[end]]++;

            // Shrink window if any element frequency exceeds k
            while(mp[nums[end]] > k) {
                mp[nums[start]]--;
                start++;
            }

            // Update max length
            len = max(len, end - start + 1);
            end++;
        }
        return len;
    }
};