// Problem: Factorial (Recursive)
// Link: [Basic/Practice problem]
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n) - recursion stack
// Approach: Classic recursion

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fact(int n) {
        if(n <= 1) 
            return 1;
        
        return n * fact(n - 1);
    }
    
    int factorial(int n) {
        return fact(n);
    }
};