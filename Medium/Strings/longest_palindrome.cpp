// Problem: Longest Palindrome
// Link: https://leetcode.com/problems/longest-palindrome/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1) - fixed size arrays
// Approach: Count character frequencies, use even counts + at most one odd

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count frequencies
        for(char c : s) {
            if(c >= 'a') {
                lower[c - 'a']++;
            } else {
                upper[c - 'A']++;
            }
        }
        
        int count = 0;
        int odd = 0;
        
        for(int i = 0; i < 26; i++) {
            // For lowercase
            if(lower[i] % 2 == 0) {  // Even count
                count += lower[i];    
            } else {  // Odd count
                count += lower[i] - 1;
                odd = 1;
            }
            
            // For uppercase
            if(upper[i] % 2 == 0) {  // Even count
                count += upper[i];    
            } else {  // Odd count
                count += upper[i] - 1;
                odd = 1;
            } 
        }
        
        return count + odd;
    }
};