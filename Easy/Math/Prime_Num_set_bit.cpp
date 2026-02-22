// Problem: Prime Number of Set Bits in Binary Representation
// Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Difficulty: Easy
// Time Complexity: O(n * sqrt(log n))
// Space Complexity: O(1)
// Approach: Count set bits, check if count is prime

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) 
            return false;
        
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) 
                return false;
        }
        
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int result = 0;
        
        for(int i = left; i <= right; i++) {
            int bits = __builtin_popcount(i);  // Count set bits
            if(isPrime(bits)) 
                result++;
        }
        
        return result;
    }
};