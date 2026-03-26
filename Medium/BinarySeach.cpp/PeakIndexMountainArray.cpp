// Problem: Peak Index in a Mountain Array
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Difficulty: Medium
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Binary search, move towards increasing side

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            else if(arr[mid] > arr[mid - 1]) 
            st  = mid + 1;
            else                            
             end = mid - 1;
        }
        return -1;
    }
};