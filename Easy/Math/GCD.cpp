// Problem: GCD of Two Numbers
// Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Difficulty: Easy
// Time Complexity: O(log(min(a,b)))
// Space Complexity: O(log(min(a,b))) - recursion stack
// Approach: Euclidean Algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive Euclidean Algorithm
    int gcd(int a, int b) {
        if(b == 0) 
            return a;
        
        return gcd(b, a % b);
    }
    
    // Iterative version (alternative)
    /*
    int gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    */
};