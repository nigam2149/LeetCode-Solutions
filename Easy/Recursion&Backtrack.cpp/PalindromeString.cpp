// Problem: Palindrome String Check (Recursive)
// Link: https://leetcode.com/problems/valid-palindrome/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n) - recursion stack
// Approach: Two pointers recursion from both ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palind(string& s, int i, int j) {
        // Base case: pointers crossed or met
        if(i >= j) {
            return true;
        }
        
        // Check if characters don't match
        if(s[i] != s[j]) 
            return false;
        
        // Recursively check remaining string
        return palind(s, i + 1, j - 1);
    }
    
    bool isPalindrome(string& s) {
        int i = 0, j = s.size() - 1;
        return palind(s, i, j);
    }
};