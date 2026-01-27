// Problem: Merge Sorted Array
// Link: https://leetcode.com/problems/merge-sorted-array/
// Difficulty: Easy
// Time Complexity: O(m + n)
// Space Complexity: O(1)
// Approach: Two pointers from end

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int indx = m + n - 1;
        
        while(i >= 0 && j >= 0) {
            if(nums1[i] <= nums2[j]) {
                nums1[indx] = nums2[j];
                j--;
                indx--;
            } else {
                nums1[indx] = nums1[i];
                i--;
                indx--;
            }
        }
        
        while(j >= 0) {
            nums1[indx] = nums2[j];
            j--;
            indx--;
        }
    }
};