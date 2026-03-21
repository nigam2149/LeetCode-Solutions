// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1) - fixed size array (256)
// Approach: Sliding window with frequency array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> count(256, 0);  // ASCII characters
        int st = 0, end = 0, len = 0;
        
        while(end < s.size()) {
            // Remove duplicates from substring
            while(count[s[end]]) {
                count[s[st]] = 0;
                st++;
            }
            
            // Add current character
            count[s[end]] = 1;
            
            // Update max length
            len = max(len, end - st + 1);
            end++;
        }
        
        return len;
    }
};