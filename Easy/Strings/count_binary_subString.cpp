// Problem: Count Binary Substrings
// Link: https://leetcode.com/problems/count-binary-substrings/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Count consecutive groups, add min of adjacent groups

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int result = 0;
        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                curr++;  // Same character, extend current group
            } else {
                result += min(prev, curr);  // Add valid substrings
                prev = curr;  // Previous group becomes current
                curr = 1;     // Start new group
            }
        }
        
        // Add for last group
        result += min(prev, curr);
        
        return result;
    }
};