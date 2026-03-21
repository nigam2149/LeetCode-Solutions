// Problem: Subarray Sums Divisible by K
// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(k)
// Approach: Prefix sum with modulo and hash map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Map to store (remainder, count)
        unordered_map<int, int> m;
        m[0] = 1;  // Initially (0, 1)
        
        int prefixSum = 0, rem, total = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            rem = prefixSum % k;
            
            // Handle negative remainder
            if(rem < 0) {
                rem = k + rem;
            }
            
            // Add count of previous occurrences of this remainder
            total += m[rem];
            
            // Update count of current remainder
            m[rem]++;
        }
        
        return total;
    }
};