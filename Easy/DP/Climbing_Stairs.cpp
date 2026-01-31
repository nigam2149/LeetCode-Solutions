// Problem: Climbing Stairs
// Link: https://leetcode.com/problems/climbing-stairs/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1) - Space optimized
// Approach: Dynamic Programming (Fibonacci pattern)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        
        // Space Optimization
        int prev1 = 2; 
        int prev2 = 1;
        
        for(int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};