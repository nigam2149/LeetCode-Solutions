// Problem: Palindrome Number
// Link: https://leetcode.com/problems/palindrome-number/
// Difficulty: Easy
// Time Complexity: O(log n) - number of digits
// Space Complexity: O(1)
// Approach: Reverse number and compare

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        if(n < 0) return false;  // Negative numbers are not palindromes
        
        int temp = n;
        int rev = 0;
        
        while(n > 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n = n / 10;
        }
        
        return temp == rev;
    }
};