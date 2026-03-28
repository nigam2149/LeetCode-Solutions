// Problem: Count Zeros in a Sorted Binary Array
// Link: https://www.geeksforgeeks.org/problems/count-zeros-in-a-sorted-binary-array1455/1
// Difficulty: Easy
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Approach: Binary search to find first 0, then count remaining

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countZeroes(vector<int>& arr) {
        int st = 0, end = arr.size() - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(arr[mid] == 1) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return arr.size() - st;
    }
};