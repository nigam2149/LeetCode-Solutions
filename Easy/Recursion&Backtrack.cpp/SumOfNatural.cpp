// Problem: Sum of First N Natural Numbers (Recursive)
// Link: [Practice/Basic problem]
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n) - recursion stack
// Approach: Recursion with accumulator

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sum(int n, int& ans) {
        if(n == 0) {  // Base case
            return;
        }
        
        ans += n;
        sum(n - 1, ans);
    }
    
    int findSum(int n) {
        int ans = 0;
        sum(n, ans);
        return ans;
    }
};
