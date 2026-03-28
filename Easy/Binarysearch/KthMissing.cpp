// Problem: Kth Missing Positive Number
// Link: https://leetcode.com/problems/kth-missing-positive-number/
// Difficulty: Easy
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Binary search on count of missing numbers before mid

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int st = 0, e = arr.size() - 1;
        int ans = arr.size();

        while(st <= e) {
            int mid = st + (e - st) / 2;

            // Missing numbers before mid = arr[mid] - mid - 1
            if(arr[mid] - mid - 1 >= k) {
                ans = mid;
                e = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans + k;
    }
};