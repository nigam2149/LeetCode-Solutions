// Problem: Count Digits in a Number
// Link: [Basic/Practice problem]
// Difficulty: Easy
// Time Complexity: O(log n) - number of digits
// Space Complexity: O(1)
// Approach: Keep dividing by 10

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        if(n == 0) return 1;  // Edge case: 0 has 1 digit
        
        int count = 0;
        while(n > 0) {
            int digit = n % 10;
            n = n / 10;
            count++;
        }
        
        return count;
    }
};