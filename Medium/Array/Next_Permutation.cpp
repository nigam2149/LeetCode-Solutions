// Problem:Next Permutation
// Link: https://leetcode.com/problems/next-permutation/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Algorithm: Find pivot, find swap, swap and reverse

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Find the pivot (gola_index)
        int gola_index = -1;
        for(int i = n - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                gola_index = i - 1;
                break;
            }
        }
        
        // If no pivot found, array is in descending order
        if(gola_index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find the element to swap with pivot
        int swap_index = gola_index;
        for(int i = n - 1; i > gola_index; i--) {
            if(nums[i] > nums[gola_index]) {
                swap_index = i;
                break;
            }
        }
        swap(nums[gola_index], nums[swap_index]);

        reverse(nums.begin() + gola_index + 1, nums.end());
    }
};