// Problem: Search Insert Position
// Link: https://leetcode.com/problems/search-insert-position/
// Difficulty: Easy
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Binary search, track index when target is less than mid

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int st = 0, e = arr.size() - 1;
        int index = arr.size();

        while(st <= e) {
            int mid = st + (e - st) / 2;

            if(arr[mid] == target)      return mid;
            else if(arr[mid] < target)  st    = mid + 1;
            else { index = mid;         e     = mid - 1; }
        }
        return index;
    }
};