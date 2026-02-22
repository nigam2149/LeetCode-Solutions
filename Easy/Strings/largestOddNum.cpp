// Problem: Largest Odd Number in String
// Link: https://leetcode.com/problems/largest-odd-number-in-string/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Find last odd digit, return substring

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--) {
            if((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";   
    }
};