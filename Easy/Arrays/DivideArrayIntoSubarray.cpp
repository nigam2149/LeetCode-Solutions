// Problem: Divide an Array Into Subarrays With Minimum Cost I
// Link: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: First element fixed, find 2nd and 3rd minimum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int firstMin  = nums[0];
        int secondMin = INT_MAX;
        int thirdMin  = INT_MAX;

        for(int i = 1; i < n; i++) {
            if(nums[i] < secondMin) {
                thirdMin  = secondMin;
                secondMin = nums[i];
            } else if(nums[i] < thirdMin) {
                thirdMin = nums[i];
            }
        }

        return firstMin + secondMin + thirdMin;  
    }
};