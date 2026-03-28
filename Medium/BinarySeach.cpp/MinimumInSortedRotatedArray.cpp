// Problem: Find Minimum in Rotated Sorted Array
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Difficulty: Medium
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Binary search, move towards unsorted half

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int st = 0, e = arr.size() - 1;
        int ans = arr[0];

        while(st <= e) {
            int mid = st + (e - st) / 2;

            if(arr[mid] >= arr[e]) {
                ans = arr[mid];
                st = mid + 1;
            } else {
                ans = arr[mid];
                e = mid;
            }
        }
        return ans;
    }
};