// Problem: Count Subarrays with Sum Equal to 0
// Link: https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Prefix sum with hash map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubarray(vector<int>& arr) {
        // Map to store (prefix_sum, count)
        map<int, int> mp;
        int prefix = 0;
        int ans = 0;
        
        // Initial case: empty subarray has sum 0
        mp[0] = 1;  // Edge case ke liye
        
        for(int i = 0; i < arr.size(); i++) {
            prefix += arr[i];
            
            // If this prefix sum seen before, add count
            if(mp.count(prefix)) {
                ans += mp[prefix];
            }
            
            // Update count of current prefix sum
            mp[prefix]++;
        }
        
        return ans;
    }
};