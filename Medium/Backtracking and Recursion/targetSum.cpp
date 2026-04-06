// Problem: Target Sum
// Link: https://leetcode.com/problems/target-sum/
// Difficulty: Medium
// Time Complexity: O(2^n)
// Space Complexity: O(n) - recursion stack
// Approach: Recursion, add or subtract each element to reach target

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long find(vector<int>& A, int index, int n, int target) {
        if(target == 0 && index == n) return 1;
        if(index == n)                return 0;

        // Include with + sign
        long long include = find(A, index + 1, n, target - A[index]);

        // Include with - sign
        long long exclude = find(A, index + 1, n, target + A[index]);

        return include + exclude;
    }

    long long findTargetSumWays(int n, vector<int>& A, int target) {
        return find(A, 0, n, target);
    }
};