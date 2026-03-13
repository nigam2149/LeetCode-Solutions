// Problem: Factorial Trailing Zeroes
// Link: https://leetcode.com/problems/factorial-trailing-zeroes/
// Difficulty: Medium
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Approach: Count factors of 5 (pairs of 2*5 make 10)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        
        // Count how many times 5 is a factor
        while(n >= 5) {
            n /= 5;
            count += n;
        }
        
        return count;
    }
};