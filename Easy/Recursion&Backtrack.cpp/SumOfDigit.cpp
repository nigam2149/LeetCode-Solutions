// Problem: Sum of Digits (Recursive)
// Link: [Practice/Basic problem]
// Difficulty: Easy
// Time Complexity: O(log n) - number of digits
// Space Complexity: O(log n) - recursion stack
// Approach: Extract last digit, recurse on remaining

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum(int n) {
        if(n == 0) {
            return 0;
        }
        
        return (n % 10) + sum(n / 10);
    }
    
    int sumOfDigits(int n) {
        return sum(n);
    }
};