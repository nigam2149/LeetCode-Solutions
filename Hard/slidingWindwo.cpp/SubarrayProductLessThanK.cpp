// Problem: Subarray Product Less Than K
// Link: https://leetcode.com/problems/subarray-product-less-than-k/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Sliding window with two pointers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;  // Edge case
        
        int count = 0, start = 0, end = 0;
        int n = nums.size(), product = 1;
        
        while(end < n) {
            product *= nums[end];
            
            // Shrink window if product >= k
            while(product >= k && start <= end) {
                product /= nums[start];
                start++;
            }
            
            // Add count of all subarrays ending at 'end'
            count += (end - start + 1);
            end++;
        }
        
        return count;
    }
};