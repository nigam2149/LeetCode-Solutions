// Problem: LCM of Two Numbers
// Link: [Basic/Practice problem]
// Difficulty: Easy
// Time Complexity: O(log(min(a,b)))
// Space Complexity: O(1)
// Approach: LCM = (a * b) / GCD(a, b)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) 
            return a;
        return gcd(b, a % b);
    }
    
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    
};