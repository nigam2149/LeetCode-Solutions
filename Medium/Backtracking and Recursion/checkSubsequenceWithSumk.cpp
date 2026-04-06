// Problem: Check if Subsequence Sum Equals K
// Link: https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1
// Difficulty: Easy
// Time Complexity: O(2^n)
// Space Complexity: O(n) - recursion stack
// Approach: Recursion, include or exclude each element

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(int n, vector<int>& arr, int k, int sum, int indx) {
        if(sum > k)    return false;
        if(indx == n)  return sum == k;

        // Include current element
        if(check(n, arr, k, sum + arr[indx], indx + 1)) return true;

        // Exclude current element
        if(check(n, arr, k, sum, indx + 1)) return true;

        return false;
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return check(n, arr, k, 0, 0);
    }
};