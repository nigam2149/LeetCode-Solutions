// Problem: Remove Outermost Parentheses
// Link: https://leetcode.com/problems/remove-outermost-parentheses/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach: Track balance, skip outermost parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        
        for(char c : s) {
            if(c == '(') {
                if(count > 0) {
                    ans += c;
                }
                count++;
            } else {
                count--;
                if(count > 0) {
                    ans += c;
                }
            }
        }
        
        return ans;
    }
};