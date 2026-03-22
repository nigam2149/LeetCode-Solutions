// Problem: Count Subarrays Where Max Element Appears at Least K Times
// Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Sliding window with max element frequency tracking

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        // Find max element
        int maxEle = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            maxEle = max(maxEle, nums[i]);
        }

        long long total = 0;
        int count = 0, start = 0, end = 0;

        while(end < n) {
            if(nums[end] == maxEle) {
                count++;
            }

            // Add count of all valid subarrays starting from current window
            while(count == k) {
                total += (n - end);
                if(nums[start] == maxEle) {
                    count--;
                }
                start++;
            }
            end++;
        }
        return total;
    }
};