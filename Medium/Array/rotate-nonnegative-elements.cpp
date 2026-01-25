// Problem: Rotate Non-Negative Elements
// Link: https://leetcode.com/contest/weekly-contest-486/problems/rotate-non-negative-elements/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNeg;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                nonNeg.push_back(nums[i]);
            }
        }
        
        int size = nonNeg.size();
        if(size == 0) return nums;
        
        // Rotate left by k
        k = k % size; 
        rotate(nonNeg.begin(), nonNeg.begin() + k, nonNeg.end());  // Fixed: rotate nonNeg, not nums

        int idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                nums[i] = nonNeg[idx++];
            }
        }
        
        return nums;
    }
};